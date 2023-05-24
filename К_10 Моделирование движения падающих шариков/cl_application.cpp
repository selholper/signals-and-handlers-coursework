#include "cl_application.h"
#include "Input.h"
#include "RemoteControl.h"
#include "Field.h"
#include "Ball.h"
#include "Output.h"

cl_application::cl_application(cl_base *parent, std::string name) : cl_base (parent, name) {}

void cl_application::build_tree_objects() {
    cl_application *system = this;
    Input *input = new Input(system, "input");
    RemoteControl *remote_control = new RemoteControl(system, "remote_control");
    Field *field = new Field(system, "field");
    Output *output = new Output(system, "output");
    std::vector <Ball *> balls;

    system->set_mark(1);
    input->set_mark(1);
    field->set_mark(1);

    system->set_connect(SIGNAL_D(cl_application::signal_read), input, HANDLER_D(Input::handler_read));
    input->set_connect(SIGNAL_D(Input::signal_read), field, HANDLER_D(Field::handler_read));
    input->set_connect(SIGNAL_D(Input::signal_system), system, HANDLER_D(cl_application::handler_input));
    input->set_connect(SIGNAL_D(Input::signal_system_load_data), input, HANDLER_D(Input::handler_system_load_data));
    input->set_connect(SIGNAL_D(Input::signal_showtree), input, HANDLER_D(Input::handler_showtree));
    field->set_connect(SIGNAL_D(Field::signal_init_field_size), field, HANDLER_D(Field::handler_init_field_size));
    field->set_connect(SIGNAL_D(Field::signal_init_field_row), field, HANDLER_D(Field::handler_init_field_row));
    field->set_connect(SIGNAL_D(Field::signal_end_of_input), input, HANDLER_D(Input::handler_end_of_input));

    while(this->state_of_system != "endtree") {
        emit_signal(SIGNAL_D(cl_application::signal_read), "");
        input->emit_signal(SIGNAL_D(Input::signal_system_load_data), "");
        if (state_of_system.find(' ') != std::string::npos) {
            size_t pos = state_of_system.find(' ');
            std::string s = state_of_system.substr(0, pos);
            int m = stoi(s);

            balls.resize(m);
            for (int i = 0; i < m; ++i) {
                balls[i] = new Ball(field, "ball_" + std::to_string(i + 1));
                balls[i]->set_mark(1);
                balls[i]->set_connect(SIGNAL_D(Ball::signal_set_position), balls[i], HANDLER_D(Ball::handler_set_position));
                field->set_connect(SIGNAL_D(Field::signal_request_position), balls[i], HANDLER_D(Ball::handler_request_position));
                balls[i]->set_connect(SIGNAL_D(Ball::signal_ball_processing), field, HANDLER_D(Field::handler_ball_processing));
                balls[i]->set_connect(SIGNAL_D(Ball::signal_output_balls_pos), output, HANDLER_D(Output::handler_output_balls_pos));
                balls[i]->set_connect(SIGNAL_D(Ball::signal_end_clock), remote_control, HANDLER_D(RemoteControl::handler_end_clock));
                balls[i]->set_connect(SIGNAL_D(Ball::signal_output_winning_balls), output, HANDLER_D(Output::handler_output_winning_balls));
                field->set_connect(SIGNAL_D(Field::signal_change_position), balls[i], HANDLER_D(Ball::handler_change_position));
                field->set_connect(SIGNAL_D(Field::signal_output_balls_pos), balls[i], HANDLER_D(Ball::handler_output_balls_pos));
                field->set_connect(SIGNAL_D(Field::signal_check_winning_balls), balls[i], HANDLER_D(Ball::handler_check_winning_balls));
                balls[i]->emit_signal(SIGNAL_D(Ball::signal_set_position), std::to_string(i + 1));
            }
        }
    }

    // Установка не достающих связей сигналов и обработчиков между объектами
    system->set_connect(SIGNAL_D(cl_application::signal_clock_run), remote_control, HANDLER_D(RemoteControl::handler_clock_run));
    remote_control->set_connect(SIGNAL_D(RemoteControl::signal_field_processing), field, HANDLER_D(Field::handler_field_processing));
    field->set_connect(SIGNAL_D(Field::signal_end_clock), remote_control, HANDLER_D(RemoteControl::handler_end_clock));
    remote_control->set_connect(SIGNAL_D(RemoteControl::signal_end_clock), system, HANDLER_D(cl_application::handler_end_clock));
}

int cl_application::exec_app() {
    set_ready_branch(); // Приведение всех объектов в состояние готовности

    while (this->state_of_system != "endclock") {
        emit_signal(SIGNAL_D(cl_application::signal_clock_run), "");
    }

	return 0;
}

void cl_application::signal_read(std::string &s) {}

void cl_application::signal_clock_run(std::string &s) {}

void cl_application::handler_input(std::string s) {
    this->state_of_system = s;
}

void cl_application::handler_end_clock(std::string s) {
    this->state_of_system = "endclock";
}

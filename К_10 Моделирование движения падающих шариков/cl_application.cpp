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
    output->set_mark(1);

    system->set_connect(SIGNAL_D(cl_application::signal_read), input, HANDLER_D(Input::handler_read));
    input->set_connect(SIGNAL_D(Input::signal_read), field, HANDLER_D(Field::handler_read));
    input->set_connect(SIGNAL_D(Input::signal_system), system, HANDLER_D(cl_application::handler_input));
    input->set_connect(SIGNAL_D(Input::signal_system_load_data), input, HANDLER_D(Input::handler_system_load_data));
    input->set_connect(SIGNAL_D(Input::signal_showtree), input, HANDLER_D(Input::handler_showtree));
    field->set_connect(SIGNAL_D(Field::signal_init_field_size), field, HANDLER_D(Field::handler_init_field_size));
    field->set_connect(SIGNAL_D(Field::signal_init_field_row), field, HANDLER_D(Field::handler_init_field_row));
    field->set_connect(SIGNAL_D(Field::signal_end_of_input), input, HANDLER_D(Input::handler_end_of_input));

    while(this->data != "endtree") {
        emit_signal(SIGNAL_D(cl_application::signal_read), "");
        input->emit_signal(SIGNAL_D(Input::signal_system_load_data), "");
        if (data.find(' ') != std::string::npos) {
            size_t pos = data.find(' ');
            std::string s = data.substr(0, pos);
            int m = stoi(s);

            balls.resize(m);
            for (int i = 0; i < m; ++i) {
                balls[i] = new Ball(field, "ball_" + std::to_string(i + 1));
                balls[i]->set_mark(1);
                balls[i]->set_connect(SIGNAL_D(Ball::signal_set_position), balls[i], HANDLER_D(Ball::handler_set_position));
                balls[i]->emit_signal(SIGNAL_D(Ball::signal_set_position), std::to_string(i + 1));
            }
        }
    }

    // Установка не достающих связей сигналов и обработчиков между объектами
}

int cl_application::exec_app() {
    set_ready_branch(); // Приведение всех объектов в состояние готовности

    cl_application *system = this;

	return 0;
}

void cl_application::signal_read(std::string &s) {}

void cl_application::handler_input(std::string s) {
    this->data = s;
}

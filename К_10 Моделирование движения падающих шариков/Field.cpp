#include "Field.h"

Field::Field(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void Field::signal_init_field_size(std::string &s) {}

void Field::signal_init_field_row(std::string &s) {}

void Field::signal_end_of_input(std::string &s) {}

void Field::signal_request_position(std::string &s) {}

void Field::signal_end_clock(std::string &s) {}

void Field::signal_change_position(std::string &s) {}

void Field::signal_check_winning_balls(std::string &s) {}

void Field::signal_output_balls_pos(std::string &s) {}

void Field::handler_read(std::string s) {
    if (s.find(' ') != std::string::npos) {
        emit_signal(SIGNAL_D(Field::signal_init_field_size), s);
    } else {
        emit_signal(SIGNAL_D(Field::signal_init_field_row), s);
    }
}

void Field::handler_init_field_size(std::string s) {
    size_t pos = s.find(' ');
    std::string s1 = s.substr(0, pos),
                s2 = s.substr(pos + 1);
    int column = std::stoi(s1);
    int row = std::stoi(s2);

    this->m = column;
    this->n = row;

    if (this->n == 1)
        emit_signal(SIGNAL_D(Field::signal_end_of_input), "");
}

void Field::handler_init_field_row(std::string s) {
    obstacles.push_back(s);

    if (obstacles.size() == n - 1)
        emit_signal(SIGNAL_D(Field::signal_end_of_input), "");
}

void Field::handler_field_processing(std::string s) {
    if (this->n == 1) {
        emit_signal(SIGNAL_D(Field::signal_end_clock), "");
        return;
    }

    emit_signal(SIGNAL_D(Field::signal_request_position), "");
}

void Field::handler_ball_processing(std::string s) {
    size_t pos = s.find(' ');

    int row = stoi(s.substr(0, pos));
    int column = stoi(s.substr(pos + 1));

    if (obstacles[row - 1][column - 1] == '0') {
        emit_signal(SIGNAL_D(Field::signal_change_position), s);
    } else
        obstacles[row - 1][column - 1] = '0';

    if (this->m == column) {
        emit_signal(SIGNAL_D(Field::signal_output_balls_pos), std::to_string(this->m));
        emit_signal(SIGNAL_D(Field::signal_check_winning_balls), std::to_string(this->n));
    }

}

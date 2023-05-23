#include "Field.h"

Field::Field(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void Field::signal_init_field_size(std::string &s) {}

void Field::signal_init_field_row(std::string &s) {}

void Field::signal_end_of_input(std::string &s) {}

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

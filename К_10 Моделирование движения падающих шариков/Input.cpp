#include "Input.h"

Input::Input(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void Input::signal_read(std::string &s) {}

void Input::signal_system_load_data(std::string &s) {
    emit_signal(SIGNAL_D(Input::signal_system), data);
}

void Input::signal_system(std::string &s) {}

void Input::signal_showtree(std::string &s) {}

void Input::handler_read(std::string s) {
    std::getline(std::cin, data);

    if (data == "SHOWTREE")
        emit_signal(SIGNAL_D(Input::signal_showtree), s);
    else {
        emit_signal(SIGNAL_D(Input::signal_read), data);
    }

}

void Input::handler_system_load_data(std::string s) {}

void Input::handler_showtree(std::string s) {
    cl_base *root = this;
    while(root->get_parent() != nullptr)
        root = root->get_parent();
    root->show_tree_with_marks();
    exit(1);
}

void Input::handler_end_of_input(std::string s) {
    this->data = "endtree";
}


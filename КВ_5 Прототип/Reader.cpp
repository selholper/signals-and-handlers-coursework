#include "Reader.h"

Reader::Reader(cl_base *parent, std::string name) : cl_base(parent, name) {}

bool Reader::is_entry_completed() {
    return true;
}

void Reader::signal_showtree(std::string &message) {}

void Reader::handler_commands(std::string message) {
    std::string command;

    std::getline(std::cin, command);

    if (command == "SHOWTREE") {
        show_tree_with_marks();
        exit(1);
    }
}

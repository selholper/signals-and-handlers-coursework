#include "cl_derived5.h"

cl_derived5::cl_derived5(cl_base *parent, std::string name) : cl_base(parent, name) { // Вызов конструктора базового класса
	set_cl_number(5);
}

void cl_derived5::signal(std::string &s) {
	s += " (class: 5)";
	std::cout << std::endl << "Signal from " << get_coordinate();
}

void cl_derived5::handler(std::string s) {
	std::cout << std::endl << "Signal to " << get_coordinate() << " Text:  " << s;
}

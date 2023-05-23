#include "cl_derived6.h"

cl_derived6::cl_derived6(cl_base *parent, std::string name) : cl_base(parent, name) { // Вызов конструктора базового класса
	set_cl_number(6);
}

void cl_derived6::signal(std::string &s) {
	s += " (class: 6)";
	std::cout << std::endl << "Signal from " << get_coordinate();
}

void cl_derived6::handler(std::string s) {
	std::cout << std::endl << "Signal to " << get_coordinate() << " Text:  " << s;
}

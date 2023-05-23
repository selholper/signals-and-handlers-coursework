#include "cl_derived3.h"

cl_derived3::cl_derived3(cl_base *parent, std::string name) : cl_base(parent, name) { // Вызов конструктора базового класса
	set_cl_number(3);
}

void cl_derived3::signal(std::string &s) {
	s += " (class: 3)";
	std::cout << std::endl << "Signal from " << get_coordinate();
}

void cl_derived3::handler(std::string s) {
	std::cout << std::endl << "Signal to " << get_coordinate() << " Text:  " << s;
}

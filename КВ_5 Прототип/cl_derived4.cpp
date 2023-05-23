#include "cl_derived4.h"

cl_derived4::cl_derived4(cl_base *parent, std::string name) : cl_base(parent, name) { // Вызов конструктора базового класса
	set_cl_number(4);
}

void cl_derived4::signal(std::string &s) {
	s += " (class: 4)";
	std::cout << std::endl << "Signal from " << get_coordinate();
}

void cl_derived4::handler(std::string s) {
	std::cout << std::endl << "Signal to " << get_coordinate() << " Text:  " << s;
}

#include "cl_derived2.h"

input_reader::input_reader(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void input_reader::signal(std::string &s) {
	s += " (class: 2)";
	std::cout << std::endl << "Signal from " << get_coordinate();
}

void input_reader::handler(std::string s) {
	std::cout << std::endl << "Signal to " << get_coordinate() << " Text:  " << s;
}

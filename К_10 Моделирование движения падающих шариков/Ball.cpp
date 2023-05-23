#include "Ball.h"

Ball::Ball(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void Ball::signal_set_position(std::string &s) {}

void Ball::handler_set_position(std::string s) {
    row = 1;
    column = stoi(s);
}

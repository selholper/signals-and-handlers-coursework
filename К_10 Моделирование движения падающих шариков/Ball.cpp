#include "Ball.h"

Ball::Ball(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void Ball::signal_set_position(std::string &s) {}

void Ball::signal_ball_processing(std::string &s) {}

void Ball::signal_output_balls_pos(std::string &s) {}

void Ball::signal_end_clock(std::string &s) {}

void Ball::signal_output_winning_balls(std::string &s) {}

void Ball::handler_set_position(std::string s) {
    row = 1;
    column = stoi(s);
}

void Ball::handler_request_position(std::string s) {
    std::string message = std::to_string(row) + " " + std::to_string(column);
    emit_signal(SIGNAL_D(Ball::signal_ball_processing), message);
}

void Ball::handler_change_position(std::string s) {
    size_t pos = s.find(' ');
    int row = stoi(s.substr(0, pos));
    int column = stoi(s.substr(pos + 1));

    if (this->row == row && this->column == column) {
        ++this->row;
        return;
    }
}

void Ball::handler_output_balls_pos(std::string s) {
    std::string message = s + " " + std::to_string(this->row) + " " + std::to_string(this->column);
    emit_signal(SIGNAL_D(Ball::signal_output_balls_pos), message);
}

void Ball::handler_check_winning_balls(std::string s) {
    int n = stoi(s);

    if (this->row == n) {
        emit_signal(SIGNAL_D(Ball::signal_output_winning_balls), std::to_string(this->column));
        emit_signal(SIGNAL_D(Ball::signal_end_clock), "");
    }

}

#include "Output.h"

Output::Output(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void Output::handler_output_balls_pos(std::string s) {
    size_t pos1 = s.find(' ');
    size_t pos2 = s.rfind(' ');
    int field_width = stoi(s.substr(0, pos1));
    int row = stoi(s.substr(pos1 + 1, pos2));
    int column = stoi(s.substr(pos2 + 1));

    if (field_width != column)
        std::cout << row << " : ";
    else
        std::cout << row << std::endl;
}

void Output::handler_output_winning_balls(std::string s) {
    if (!this->is_out_win_ball) {
        std::cout << s;
        this->is_out_win_ball = true;
    } else
        std::cout << " : " << s;

}

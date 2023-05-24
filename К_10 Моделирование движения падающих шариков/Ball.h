#ifndef __BALL__H
#define __BALL__H
#include "cl_base.h"

class Ball : public cl_base // Наследуемый класс
{
public:
	Ball(cl_base *parent, std::string name); // Параметризированный конструктор
    void signal_set_position(std::string &s);
    void signal_ball_processing(std::string &s);
    void signal_output_balls_pos(std::string &s);
    void signal_output_winning_balls(std::string &s);
    void signal_end_clock(std::string &s);
    void handler_set_position(std::string s);
    void handler_request_position(std::string s);
    void handler_change_position(std::string s);
    void handler_output_balls_pos(std::string s);
    void handler_check_winning_balls(std::string s);

private:
    int row;
    int column;
};

#endif


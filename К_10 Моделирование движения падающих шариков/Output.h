#ifndef __OUTPUT__H
#define __OUTPUT__H
#include "cl_base.h"

class Output : public cl_base // Наследуемый класс
{
public:
	Output(cl_base *parent, std::string name); // Параметризированный конструктор
    void handler_output_balls_pos(std::string s);
    void handler_output_winning_balls(std::string s);

private:
    bool is_out_win_ball = false;
};

#endif

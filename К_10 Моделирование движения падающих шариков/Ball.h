#ifndef __BALL__H
#define __BALL__H
#include "cl_base.h"

class Ball : public cl_base // Наследуемый класс
{
public:
	Ball(cl_base *parent, std::string name); // Параметризированный конструктор
    void signal_set_position(std::string &s);
    void handler_set_position(std::string s);

private:
    int row;
    int column;
};

#endif


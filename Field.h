#ifndef __FIELD__H
#define __FIELD__H
#include "cl_base.h"

class Field : public cl_base // Наследуемый класс
{
public:
	Field(cl_base *parent, std::string name); // Параметризированный конструктор
    void signal_init_field_size(std::string &s);
    void signal_init_field_row(std::string &s);
    void signal_end_of_input(std::string &s);
    void signal_request_position(std::string &s);
    void signal_end_clock(std::string &s);
    void signal_change_position(std::string &s);
    void signal_check_winning_balls(std::string &s);
    void signal_output_balls_pos(std::string &s);
    void handler_read(std::string s);
    void handler_init_field_size(std::string s);
    void handler_init_field_row(std::string s);
    void handler_field_processing(std::string s);
    void handler_ball_processing(std::string s);

private:
    int n = 0, m = 0;
    std::vector <std::string> obstacles;
};

#endif

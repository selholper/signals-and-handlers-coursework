#ifndef __INPUT__H
#define __INPUT__H
#include "cl_base.h"

class Input : public cl_base // Наследуемый класс
{
public:
	Input(cl_base *parent, std::string name); // Параметризированный конструктор
    void signal_read(std::string &s);
    void signal_system(std::string &s);
    void signal_system_load_data(std::string &s);
    void signal_showtree(std::string &s);
    void handler_read(std::string s);
    void handler_system_load_data(std::string s);
    void handler_showtree(std::string s);
    void handler_end_of_input(std::string s);

private:
    std::string data;
};

#endif

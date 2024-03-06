#ifndef __REMOTECONTROL__H
#define __REMOTECONTROL__H
#include "cl_base.h"

class RemoteControl : public cl_base // Наследуемый класс
{
public:
	RemoteControl(cl_base *parent, std::string name); // Параметризированный конструктор
    void signal_field_processing(std::string &s);
    void signal_end_clock(std::string &s);
    void handler_clock_run(std::string s);
    void handler_end_clock(std::string s);
};

#endif

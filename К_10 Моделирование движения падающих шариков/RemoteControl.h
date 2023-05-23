#ifndef __REMOTECONTROL__H
#define __REMOTECONTROL__H
#include "cl_base.h"

class RemoteControl : public cl_base // Наследуемый класс
{
public:
	RemoteControl(cl_base *parent, std::string name); // Параметризированный конструктор
};

#endif

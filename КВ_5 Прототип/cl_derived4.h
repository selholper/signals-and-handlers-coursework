#ifndef __CL_DERIVED4__H
#define __CL_DERIVED4__H
#include "cl_base.h"

class cl_derived4 : public cl_base // Наследуемый класс с номером 4
{
public:
	cl_derived4(cl_base *parent, std::string name); // Параметризированный конструктор
	void signal(std::string &s); // Метод сигнала
	void handler(std::string s); // Метод обработчика
};

#endif

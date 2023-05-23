#ifndef __CL_DERIVED5__H
#define __CL_DERIVED5__H
#include "cl_base.h"

class cl_derived5 : public cl_base // Наследуемый класс с номером 5
{
public:
	cl_derived5(cl_base *parent, std::string name); // Параметризированный конструктор
	void signal(std::string &s); // Метод сигнала
	void handler(std::string s); // Метод обработчика
};

#endif

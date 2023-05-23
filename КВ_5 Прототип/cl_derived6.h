#ifndef __CL_DERIVED6__H
#define __CL_DERIVED6__H
#include "cl_base.h"

class cl_derived6 : public cl_base // Наследуемый класс с номером 6
{
public:
	cl_derived6(cl_base *parent, std::string name); // Параметризированный конструктор
	void signal(std::string &s); // Метод сигнала
	void handler(std::string s); // Метод обработчика
};

#endif

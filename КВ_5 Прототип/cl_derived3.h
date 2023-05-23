#ifndef __CL_DERIVED3__H
#define __CL_DERIVED3__H
#include "cl_base.h"

class cl_derived3 : public cl_base // Наследуемый класс с номером 3
{
public:
	cl_derived3(cl_base *parent, std::string name); // Параметризированный конструктор
	void signal(std::string &s); // Метод сигнала
	void handler(std::string s); // Метод обработчика
};

#endif

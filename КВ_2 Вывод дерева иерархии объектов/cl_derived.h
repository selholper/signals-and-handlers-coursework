#ifndef __CL_DERIVED__H
#define __CL_DERIVED__H
#include "cl_base.h"

class cl_derived : public cl_base // Наследуемый класс
{
public:
	cl_derived(cl_base *parent, std::string name); // Параметризированный конструктор
};

#endif

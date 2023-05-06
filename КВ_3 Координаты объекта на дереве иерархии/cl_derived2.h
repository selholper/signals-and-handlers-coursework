#ifndef CL_DERIVED2_H_INCLUDED
#define CL_DERIVED2_H_INCLUDED
#include "cl_base.h"

class cl_derived2 : public cl_base // Наследуемый класс с номером 2
{
public:
    cl_derived2(cl_base *parent, std::string name); // Параметризированный конструктор
};

#endif

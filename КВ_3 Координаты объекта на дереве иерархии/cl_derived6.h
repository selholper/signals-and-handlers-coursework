#ifndef CL_DERIVED6_H_INCLUDED
#define CL_DERIVED6_H_INCLUDED
#include "cl_base.h"

class cl_derived6 : public cl_base // Наследуемый класс с номером 2
{
public:
    cl_derived6(cl_base *parent, std::string name); // Параметризированный конструктор
};


#endif

#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include "cl_base.h"

class Field : public cl_base
{
public:
    Field(cl_base *parent, std::string name);
};

#endif // FIELD_H_INCLUDED

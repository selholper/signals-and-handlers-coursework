#ifndef WRITER_H_INCLUDED
#define WRITER_H_INCLUDED
#include "cl_base.h"

class Writer : public cl_base
{
public:
    Writer(cl_base *parent, std::string name);
};

#endif // WRITER_H_INCLUDED

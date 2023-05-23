#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED
#include "cl_base.h"

class Reader : public cl_base
{
public:
    Reader(cl_base *parent, std::string name);
    bool is_entry_completed();
    void signal_showtree(std::string &message);
    void handler_commands(std::string message);

private:
    int n, m;
    std::vector <std::vector <int>> obstacles;
};

#endif // READER_H_INCLUDED

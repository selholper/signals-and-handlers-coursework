#ifndef __CL_DERIVED6__H
#define __CL_DERIVED6__H
#include "cl_base.h"

class cl_derived6 : public cl_base // ����������� ����� � ������� 6
{
public:
	cl_derived6(cl_base *parent, std::string name); // ������������������� �����������
	void signal(std::string &s); // ����� �������
	void handler(std::string s); // ����� �����������
};

#endif

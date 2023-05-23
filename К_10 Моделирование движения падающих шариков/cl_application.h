#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"

class cl_application : public cl_base // Класс корневого объекта (приложения)
{
public:
	cl_application(cl_base *parent, std::string name = "Base_object"); // Параметризированный конструктор
	void build_tree_objects(); // Метод построения дерева иерархии объектов
	int exec_app(); // Метод запуска приложения
	void signal_read(std::string &s);
    void handler_input(std::string s);

private:
    std::string data;
    int clock_counter;
};

#endif

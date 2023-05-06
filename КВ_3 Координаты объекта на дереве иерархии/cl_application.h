#ifndef CL_APPLICATION_H_INCLUDED
#define CL_APPLICATION_H_INCLUDED
#include "cl_base.h"

class cl_application : public cl_base // Класс корневого объекта (приложения)
{
public:
    cl_application(cl_base *parent, std::string name = "Base_object"); // Параметризированный конструктор
    void build_tree_objects(); // Метод построения дерева иерархии объектов
    int exec_app(); // Метод запуска приложения
};


#endif

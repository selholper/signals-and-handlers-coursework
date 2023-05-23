#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"

class cl_application : public cl_base // Класс корневого объекта (приложения)
{
public:
	cl_application(cl_base *parent, std::string name = "Base_object"); // Параметризированный конструктор
	void build_tree_objects(); // Метод построения дерева иерархии объектов
	int exec_app(); // Метод запуска приложения
	int get_mesure_number(); // Метод получения номера текущего такта
    void signal_enter(std::string &message); // Выдача сигнала объекту чтения

private:
    int measure_number;
};

#endif

#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class cl_base // Базовый класс
{
public:
    // КВ_1
	cl_base(cl_base *parent, std::string name = "Base_object"); // Параметризированный конструктор

	~cl_base(); // Деструктор

	std::string get_name(); // Метод получения имени объекта

	cl_base* get_parent(); // Метод получения указателя на головной объект текущего объекта

	cl_base* get_child(std::string name);/* Метод получения указателя на непосредственно
											подчиненный объект по его имени */
	bool set_name(std::string name); // Метод редактирования имени объекта.

    // КВ_2
    cl_base* get_obj_on_branch(std::string name);

    cl_base* get_obj_on_tree(std::string name);

	void show_tree(int level); // Метод вывода наименований объектов в дереве иерархии

    void show_tree_with_mark(int level);

    void set_mark(int state);

private:
    int state = 0;
	std::string name; // Наименование объекта
	std::vector <cl_base *> children; // Указатели на подчиненные объекты
	cl_base *parent; // Указатель на головной объект для текущего объекта
};



#endif

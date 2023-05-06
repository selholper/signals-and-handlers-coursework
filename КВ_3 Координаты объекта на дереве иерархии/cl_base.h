#ifndef CL_BASE_H_INCLUDED
#define CL_BASE_H_INCLUDED
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class cl_base // Базовый класс
{
public:
    cl_base(cl_base *parent, std::string name = "Base_object"); // Параметризированный конструктор
    ~cl_base(); // Деструктор
    std::string get_name(); // Метод получения имени объекта
    cl_base* get_parent(); // Метод получения указатедя на головной объект
    cl_base* get_child(std::string name); /*Метод получения указателя на непосредственно
                                            подчиненный объект по его имени */
    bool set_name(std::string name); // Метод редактирования имени объекта
    cl_base* get_obj_on_branch(std::string name); /*Метод поиска объекта на ветке дереве
                                                    иерархии от текущего по имени */
    cl_base* get_obj_on_tree(std::string name); // Метод поиска объекта на дереве иерархии по имени
    void show_tree(int level = 0); // Метод вывода иерархии объектов
    void show_tree_with_marks(int level = 0); // Метод вывода иерархии объектов и отметок их готовности
    void set_mark(int state); // Метод установки готовности объекта
    bool change_parent(cl_base *new_parent); // Метод переопределения головного объекта для текущего
    void remove_by_name(std::string name); // Метод удаления подчиненного объекта по наименованию
    cl_base* get_obj_by_path(std::string path); /*  Метод получения указателя на любой объект в составе
                                                    дерева иерархии объектов согласно пути (координаты) */

private:
    int state = 0; // Состояние объекта
    std::string name; // Наименование объекта
    std::vector <cl_base *> children; // Указатели на подчиненные объекты
    cl_base *parent; // Указатель на головной объект для текущего объекта
};

#endif

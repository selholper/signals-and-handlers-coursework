#include "cl_base.h"

cl_base::cl_base(cl_base *parent, std::string name) {
    this->parent = parent; // Инициализация свойств класса аргументами
    this->name = name;
    if (this->parent != nullptr)
        this->parent->children.push_back(this);
}

cl_base::~cl_base() {
    for (int i = 0; i < this->children.size(); ++i)
        delete this->children[i];
}

std::string cl_base::get_name() {
    return this->name;
}

cl_base* cl_base::get_parent() {
    return this->parent;
}

cl_base* cl_base::get_child(std::string name) {
    for (cl_base *child : this->children) // Проход по всем указателям в children
        if (child->name == name)
            return child; // Объект найден

    return nullptr; // Объект не найден
}

bool cl_base::set_name(std::string name) { // Проход по всем указателям в children
    for (cl_base* child : this->children)
        if (child->name == name)
            return false;
    this->name = name; // Присвоение аргумента, если дочерний объект с таким именем найден

    return true;
}

cl_base* cl_base::get_obj_on_branch(std::string name) {
    cl_base *result = nullptr;
    std::queue <cl_base*> ptr_queue;

    // Обход дерева объектов в ширину
    ptr_queue.push(this);
    while (!ptr_queue.empty()) {
        cl_base *ptr = ptr_queue.front();
        ptr_queue.pop();

        if (ptr->name == name && result == nullptr) // Первое вхождение объекта в дерево
            result = ptr;
        else if (ptr->name == name)
            return nullptr;

        for (cl_base *child : ptr->children)
            ptr_queue.push(child); // Добавляем в очередь дочерние объекты
    }

    return result;
}

cl_base* cl_base::get_obj_on_tree(std::string name) {
    cl_base *ptr = this;
    while (ptr->parent != nullptr) // Если объект не корневой
        ptr = ptr->parent; // Продвигаем объект вверх в дереве иерархии

    return ptr->get_obj_on_branch(name); // Поиск из корневого объекта
}

void cl_base::show_tree(int level) {
    std::cout << std::endl;
    for (int i = 0; i < 4 * level; ++i)
    std::cout << ' '; // Вывод отступов
    std::cout << name; // Вывод имени
    // Рекурсивно вызываем метод для всех объектов, подчиненных текущему
    for (cl_base *child : children)
        child->show_tree(level + 1);
}

void cl_base::show_tree_with_marks(int level) {
    std::cout << std::endl;
    for (int i = 0; i < 4 * level; ++i)
    std::cout << ' '; // Вывод отступов
    std::cout << name << ' '; // Вывод имени
    // Вывод ометки о готовности
    if (state != 0)
        std::cout << "is ready";
    else
        std::cout << "is not ready";
    // Рекурсивно вызываем метод для всех объектов, подчиненных текущему
    for (cl_base *child : children)
    child->show_tree_with_marks(level + 1);
}

void cl_base::set_mark(int state) {
    if (parent == nullptr || parent->state != 0 || state == 0)
    this->state = state; // Утсановка отметки текущего объекта
    // Рекурсивно вызываем метод для всех объектов, подчиненных текущему
    if (state == 0) {
        for (cl_base *child : children)
        child->set_mark(state);
    }
}

bool cl_base::change_parent(cl_base *new_parent) {
    if (parent == new_parent)
        return true;

    if (parent == nullptr || new_parent == nullptr)
        return false;

    if (new_parent->get_child(name) != nullptr)
        return false;

    std::queue <cl_base*> ptr_queue; // Обход ветви в ширину
    ptr_queue.push(this);
    while (!ptr_queue.empty()) {
        cl_base *ptr = ptr_queue.front();
        ptr_queue.pop();

        if (ptr == new_parent) // Головной объект принадлежит ветви текущего
            return false;

        for (cl_base *child : ptr->children)
            ptr_queue.push(child); // Добавляем в очередь дочерние объекты
    }

    for (int i = 0; i < parent->children.size(); ++i)
        if (parent->children[i]->name == name) {
            parent->children.erase(parent->children.begin() + i);
            new_parent->children.push_back(this);
            this->parent = new_parent; // changed
            return true;
        }

    return false;
}

void cl_base::remove_by_name(std::string name) {
    for (int i = 0; i < children.size(); ++i)
        if (children[i]->name == name) {
            delete children[i];
            children.erase(children.begin() + i);
            return;
        }
}

cl_base* cl_base::get_obj_by_path(std::string path) {
    if (path.empty())
        return nullptr;

    cl_base *root = this;
    while (root->parent != nullptr)
        root = root->parent;

    if (path == "/")
        return root;

    if (path.substr(0, 2) == "//")
        return get_obj_on_tree(path.substr(2));

    if (path == ".")
        return this;

    if (path[0] == '.')
        return get_obj_on_branch(path.substr(1));

    if (path[0] != '/') {
        size_t i = path.find('/');
        cl_base *child = get_child((i == std::string::npos ? path : path.substr(0, i)));

        if (child == nullptr || i == std::string::npos)
            return child;

        return child->get_obj_by_path(path.substr(i + 1));
    }

    // Абсолютная координата
    return root->get_obj_by_path(path.substr(1));
}

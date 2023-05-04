#include "cl_base.h"

cl_base::cl_base(cl_base* parent, std::string name) {
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

bool cl_base::set_name(std::string name) {
	for (cl_base* child : this->children) // Проход по всем указателям в children
		if (child->name == name)
			return false;
	this->name = name; // Присвоение аргумента, если дочерний объект с таким именем не найден

	return true;
}

cl_base* cl_base::get_obj_on_branch(std::string name) {
    cl_base *result = nullptr;
    std::queue <cl_base *> ptr_queue;

    ptr_queue.push(this);
    while (!ptr_queue.empty()) {
        cl_base *ptr = ptr_queue.front();
        ptr_queue.pop();

        if (ptr->name == name && result == nullptr)
            result = ptr;
        else if (ptr->name == name)
            return nullptr;

        for (cl_base *child : ptr->children)
            ptr_queue.push(child);
    }

    return result;
}

cl_base* cl_base::get_obj_on_tree(std::string name) {
    if (parent != nullptr)
        return parent->get_obj_on_tree(name);

    return get_obj_on_branch(name);
}

void cl_base::show_tree(int level) {
    std::cout << std::endl;
    for (int i = 0; i < 4 * level; ++i)
        std::cout << ' ';
    std::cout << name;

    for (cl_base *child : children)
        child->show_tree(level + 1);
}

void cl_base::show_tree_with_mark(int level) {
    std::cout << std::endl;
    for (int i = 0; i < 4 * level; ++i)
        std::cout << ' ';
    std::cout << name << ' ';
    if (state != 0)
        std::cout << "is ready";
    else
        std::cout << "is not ready";

    for (cl_base *child : children)
        child->show_tree_with_mark(level + 1);
}

void cl_base::set_mark(int state) {
    if (parent == nullptr || parent->state != 0 || state == 0)
        this->state = state;

    if (state == 0)
        for (cl_base *child : children)
            child->set_mark(state);
}

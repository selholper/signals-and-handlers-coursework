#include <iostream>
#include <string>
#include <vector>

class cl_base
{
public:
    std::vector<cl_base*> children;

    cl_base(cl_base* parent = nullptr, std::string name = "Base_object") {
        this->parent = parent;
        this->name = name;
    }

    std::string get_name() {
        return this->name;
    }

    cl_base* get_parent() {
        return this->parent;
    }

    cl_base* get_child(std::string name) {
        for (auto child : this->children)
            if (child->name == name)
                return child;

        return nullptr;
    }

    bool set_name(std::string name) {
        for (auto child : this->children)
            if (child->name == this->name)
                return false;
        this->name = name;

        return true;
    }

    void show_tree() {
        if (this->parent == nullptr)
            std::cout << this->name;

        if (this->children.empty())
            return;

        std::cout << std::endl;
        std::cout << this->name;
        for (int i = 0; i < this->children.size() - 1; ++i)
            std::cout << "  " << this->children[i]->name;
        std::cout << "  " << this->children.back()->name;

        for (auto child : this->children)
            child->show_tree();
    }

private:
    std::string name;
    cl_base* parent;
};

class cl_application : public cl_base
{
public:
    cl_application(cl_base* parent = nullptr, std::string name = "Base_object") : cl_base(parent, name) {}

    cl_base* build_tree_objects(std::string name = "Base_object") {
        if (this->get_name() == name)
            return this;

        for (auto child : this->children)
            child->build_tree_objects(name);

        return nullptr;
    }

    int exec_app() {
        std::string root_name, name;
        cl_base *ptr = this;
        cl_base *new_ptr;

        std::cin >> name;
        ptr->set_name(name);
        std::cin >> root_name >> name;
        while (root_name != name) {
            if (ptr->get_name() == root_name) {
                new_ptr = new cl_base(ptr, name);
                ptr->children.push_back(new_ptr);
            } else {
                ptr = ptr->get_child(root_name);

                // Неверный ввод
                if (ptr == nullptr)
                    break;

                new_ptr = new cl_base(ptr, name);
                ptr->children.push_back(new_ptr);
            }
            std::cin >> root_name >> name;
        }

        show_tree();

        return 0;
    }
};

int main() {
    cl_application ob_cl_application(nullptr);
    ob_cl_application.build_tree_objects();
    return ob_cl_application.exec_app();
}

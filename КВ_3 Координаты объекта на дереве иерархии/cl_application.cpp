#include "cl_application.h"
#include "cl_derived2.h"
#include "cl_derived3.h"
#include "cl_derived4.h"
#include "cl_derived5.h"
#include "cl_derived6.h"

cl_application::cl_application(cl_base *parent, std::string name) : cl_base(parent, name) {}

void cl_application::build_tree_objects() {
    std::string path, name;
    cl_base *parent, *last;
    int cl_number;

    std::cout << "Object tree";
    std::cin >> name;
    this->set_name(name);
    last = this;
    std::cin >> path;
    while (path != "endtree") {
        std::cin >> name >> cl_number;
        parent = last->get_obj_by_path(path);

        if (parent == nullptr) {
            this->show_tree();
            std::cout << std::endl;
            std::cout << "The head object " << path << " is not found";
            exit(1);
        }

        if (parent->get_child(name) != nullptr) {
            std::cout << std::endl;
            std::cout << path << "     Dubbing the names of subordinate objects";
        } else { // parent->get_child(name) == nullptr
            switch(cl_number) {
                case 2:
                    last = new cl_derived2(parent, name);
                    break;
                case 3:
                    last = new cl_derived3(parent, name);
                    break;
                case 4:
                    last = new cl_derived2(parent, name);
                    break;
                case 5:
                    last = new cl_derived3(parent, name);
                    break;
                case 6:
                    last = new cl_derived2(parent, name);
                    break;
                default: // Неверный номер
                    break;
            }
        }

        std::cin >> path;
    }
}

int cl_application::exec_app() {
    std::string cmd, path;
    cl_base *interim, *current = this;
    std::stack <std::string> ptr_stack;

    show_tree();
    std::cin >> cmd;
    while (cmd != "END") {
        std::cin >> path;

        interim = current->get_obj_by_path(path);
        if (cmd == "SET") {
            if (interim != nullptr) {
                current = interim;
                std::cout << std::endl;
                std::cout << "Object is set: " << current->get_name();
            } else {
                std::cout << std::endl;
                std::cout << "The object was not found at the specified coordinate: " << path;
            }
        } else if (cmd == "FIND") {
            if (interim != nullptr) {
                std::cout << std::endl;
                std::cout << path << "     Object name: " << interim->get_name();
            } else {
                std::cout << std::endl;
                std::cout << path << "     Object is not found";
            }
        } else if (cmd == "MOVE") {
            if (current->change_parent(interim)) {
                std::cout << std::endl;
                std::cout << "New head object: " << interim->get_name();
            } else if (interim == nullptr) {
                std::cout << std::endl;
                std::cout << path << "     Head object is not found";
            } else if (interim->get_child(current->get_name()) != nullptr) {
                std::cout << std::endl;
                std::cout << path << "     Dubbing the names of subordinate objects";
            } else {
                std::cout << std::endl;
                std::cout << path << "     Redefining the head object failed";
            }
        } else if (cmd == "DELETE") {
            if (interim != nullptr) {
                while (interim->get_parent() != nullptr) {
                    ptr_stack.push(interim->get_name());
                    interim = interim->get_parent();
                }

                current->remove_by_name(path);
                std::cout << std::endl;
                std::cout << "The object ";
                while (!ptr_stack.empty()) {
                    std::cout << '/' << ptr_stack.top();
                    ptr_stack.pop();
                }
                std::cout << " hase been deleted";
            }
        }

        std::cin >> cmd;
    }

    std::cout << std::endl << "Current object hierarchy tree";
    show_tree(); // Вывод дерева иерархии

    return 0;
}

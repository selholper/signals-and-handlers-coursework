#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"

cl_application::cl_application(cl_base *parent, std::string name) : cl_base(parent, name) {}

void cl_application::build_tree_objects() {
	std::string root_name, name; // Объявление переменных
	int cl_number, state;
	cl_base *ptr = this;

	std::cin >> root_name;
	ptr->set_name(root_name); // Установка считанного имени
	std::cin >> root_name;
	while (root_name != "endtree") {
        std::cin >> name >> cl_number;

        ptr = get_obj_on_tree(root_name);
        if (ptr != nullptr && get_obj_on_tree(name) == nullptr) {
            switch (cl_number) {
                case 2:
                    new cl_2(ptr, name);
                    break;
                case 3:
                    new cl_3(ptr, name);
                    break;
                case 4:
                    new cl_4(ptr, name);
                    break;
                case 5:
                    new cl_5(ptr, name);
                    break;
                case 6:
                    new cl_6(ptr, name);
                    break;
                default:
                    break;
            }
        }

        std::cin >> root_name;
	}

	while (std::cin >> name) {
        std::cin >> state;
        ptr = get_obj_on_tree(name);
        if (ptr != nullptr)
            ptr->set_mark(state);
	}
}

int cl_application::exec_app() {
	std::cout << "Object tree";
	show_tree(0); // Вызов метода вывода наименований объектов
    std::cout << std::endl << "The tree of objects and their readiness";
    show_tree_with_mark(0);

	return 0;
}

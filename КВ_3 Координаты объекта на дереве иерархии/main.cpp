#include "cl_application.h"

int main()  {
    cl_application ob_cl_application(nullptr); // Создание корневого объекта
    ob_cl_application.build_tree_objects(); // Конструирование системы, построение дерева объектов
    return ob_cl_application.exec_app(); // Запуск системы
}

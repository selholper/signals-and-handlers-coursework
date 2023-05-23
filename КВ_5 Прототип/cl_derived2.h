#ifndef __CL_DERIVED2__H
#define __CL_DERIVED2__H
#include "cl_base.h"

class input_reader : public cl_base // Наследуемый класс с номером 2
{
public:
	input_reader(cl_base *parent, std::string name); // Параметризированный конструктор
	void signal(std::string &s); // Метод сигнала
	void handler(std::string s); // Метод обработчика
    int get_m(); //
    int get_n(); //
    std::vector <std::vector <int>> get_obstacles(); //

private:
    int m, n;
    std::vector <std::vector <int>> obstacles;
};

#endif

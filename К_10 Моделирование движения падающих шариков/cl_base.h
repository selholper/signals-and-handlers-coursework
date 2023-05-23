#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <iostream>
#include <vector>
#include <queue>
#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)

class cl_base // Базовый класс
{
public:
	cl_base(cl_base *parent, std::string name = "Base_object"); // Параметризированный конструктор
	~cl_base(); // Деструктор
	std::string get_name(); // Метод получения имени объекта
	cl_base* get_parent(); // Метод получения указатедя на головной объект
	cl_base* get_child(std::string name); /*Метод получения указателя на непосредственно
											подчиненный объект по его имени*/
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
	typedef void (cl_base::*TYPE_SIGNAL)(std::string &); // Указатель на метод сигнала объекта
	typedef void (cl_base::*TYPE_HANDLER)(std::string); // Указатель на метод обработчика объекта
	void emit_signal(TYPE_SIGNAL p_signal, std::string s_command); // Метод выдачи сигнала
	void set_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_handler); // Метод установки связи
	void delete_connect(TYPE_SIGNAL p_signal, cl_base *p_object, TYPE_HANDLER p_handler); // Метод удаления связи
	std::string get_coordinate(); // Возврат абсолютного пути объекта

	struct o_sh // Структура задания одной связи
	{
		TYPE_SIGNAL p_signal; // Указатель на метод сигнала
		cl_base *p_cl_base; // Указатель на целевой объект
		TYPE_HANDLER p_handler; // Указатель на метод обработчика
	};

	int get_cl_number();
	void set_cl_number(int n);

protected:
	void set_ready_branch(); // Метод установки готовности всех объектов ветви от текущего

private:
	void delete_signals(cl_base *p_object); // Метод удаления связи с объектом по адресу указателя p_object

	std::vector <o_sh *> connects; // Массив связей
	int state = 0; // Состояние объекта
	std::string name; // Наименование объекта
	std::vector <cl_base *> children; // Указатели на подчиненные объекты
	cl_base *parent; // Указатель на головной объект для текущего объекта
	int cl_number = 1; // Номер класса
};

#endif

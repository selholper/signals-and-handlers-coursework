#include "cl_application.h"
#include "Reader.h"
#include "ControlPanel.h"
#include "Field.h"
#include "Ball.h"
#include "Writer.h"

cl_application::cl_application(cl_base *parent, std::string name) : cl_base (parent, name) {
    this->measure_number = 1;
}

void cl_application::build_tree_objects() {
    cl_application *system = this; // 1.1
    Reader *reader = new Reader(system, "Reader");
    ControlPanel *control_panel = new ControlPanel(system, "ControlPanel");
    Field *field = new Field(system, "Field");
    Ball *ball;
    Writer *writer = new Writer(system, "Writer");

    while (!reader->is_entry_completed()) { // 1.2
        emit_signal(SIGNAL_D(cl_application::signal_enter), "Enter");

    }

    reader->set_connect(SIGNAL_D(Reader::signal_showtree), system, HANDLER_D(Reader::handler_commands)); // 1.3
}

int cl_application::exec_app() {
	set_ready_branch(); // 2.1



	return 0;
}

void cl_application::signal_enter(std::string &message) {}

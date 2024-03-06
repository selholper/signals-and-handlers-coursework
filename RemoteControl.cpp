#include "RemoteControl.h"

RemoteControl::RemoteControl(cl_base *parent, std::string name) : cl_base(parent, name) {} // Вызов конструктора базового класса

void RemoteControl::signal_field_processing(std::string &s) {}

void RemoteControl::signal_end_clock(std::string &s) {}

void RemoteControl::handler_clock_run(std::string s) {
    emit_signal(SIGNAL_D(RemoteControl::signal_field_processing), "");
}

void RemoteControl::handler_end_clock(std::string s) {
    emit_signal(SIGNAL_D(RemoteControl::signal_end_clock), "");
}

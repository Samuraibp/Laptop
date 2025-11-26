#include "CPU.h"
#include <iostream>
using namespace std;

CPU::CPU(const char* Name, int Core, int Flow): core(Core), flow(Flow)
{
	if (Name) {
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}
	else name = nullptr;
}

void CPU::set_CPU_name(const char* newName)
{
    if (name)
        delete[] name;

    if (!newName)
    {
        name = nullptr;
        return;
    }

    name = new char[strlen(newName) + 1];
    strcpy_s(name, strlen(newName) + 1, newName);
}


void CPU::set_CPU_core(int Core) {
    if (Core < 0) Core = 0;
    core = Core;
}


void CPU::set_CPU_flow(int Flow)
{
    if (Flow < 0) Flow = 0;
    flow = Flow;
}

const char* CPU::get_CPU_name() { return name; }

int CPU::get_CPU_core() { return core; }

int CPU::get_CPU_flow() { return flow; }

CPU::CPU(const CPU& cpu)
	: CPU(cpu.name, cpu.core, cpu.flow)
{}

CPU::~CPU() { delete[]name; }

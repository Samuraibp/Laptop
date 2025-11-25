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

void CPU::set_CPU_name(const char* Name)
{
	if (name != nullptr) delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void CPU::set_core(int Core)
{
	core = Core;
}


void CPU::set_flow(int Flow)
{
	flow = Flow;
}

const char* CPU::get_CPU_name()
{
	return name;
}

int CPU::get_core()
{
	return core;
}

int CPU::get_flow()
{
	return flow;
}

CPU::CPU(const CPU& cpu)
	: CPU(cpu.name, cpu.core, cpu.flow)
{}

CPU::~CPU()
{
	if (name != nullptr) delete[]name;
}

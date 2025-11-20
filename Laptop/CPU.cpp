#include "CPU.h"
#include <iostream>
using namespace std;

CPU::CPU(const char* Name, int Core, int Flow)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	core = Core;
	flow = Flow;
}

void CPU::set_CPU_name(const char* Name)
{
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

#include "CPU.h"
#include <iostream>
using namespace std;

CPU::CPU(const char* Name, int Core, int Flow): core(Core), flow(Flow)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void CPU::set_CPU_name()
{
	char Name[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(Name, sizeof(Name));
	if (name != nullptr) delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void CPU::set_core()
{
	int Core;
	cin >> Core;
	core = Core;
}


void CPU::set_flow()
{
	int Flow;
	cin >> Flow;
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

CPU::CPU(const CPU& cpu): core(cpu.core), flow(cpu.flow)
{
	name = new char[strlen(cpu.name) + 1];
	strcpy_s(name, strlen(cpu.name) + 1, cpu.name);
}

CPU::~CPU()
{
	if (name != nullptr) delete[]name;
}

#include "RAM.h"
#include <iostream>
using namespace std;

RAM::RAM(const char* Name, int mem, int clock, const char* type): memory(mem), clock_frequency(clock)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	memory_type = new char[strlen(type) + 1];
	strcpy_s(memory_type, strlen(type) + 1, type);
}

void RAM::set_RAM_name(const char* Name)
{
	if (name != nullptr) delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void RAM::set_RAM_memory(int mem)
{
	memory = mem;
}

void RAM::set_RAM_clock_frequency(int clock)
{
	clock_frequency = clock;
}

void RAM::set_RAM_memory_type(const char* type)
{
	if (memory_type != nullptr) delete[]memory_type;
	memory_type = new char[strlen(type) + 1];
	strcpy_s(memory_type, strlen(type) + 1, type);
}

const char* RAM::get_RAM_name()
{
	return name;
}

int RAM::get_RAM_memory()
{
	return memory;
}

int RAM::get_RAM_clock_frequency()
{
	return clock_frequency;
}

const char* RAM::get_RAM_memory_type()
{
	return memory_type;
}

RAM::RAM(const RAM& ram) : memory(ram.memory), clock_frequency(ram.clock_frequency)
{
	if (ram.name) {
		name = new char[strlen(ram.name) + 1];
		strcpy_s(name, strlen(ram.name) + 1, ram.name);
	}
	else name = nullptr;
	if (ram.memory_type) {
		memory_type = new char[strlen(ram.memory_type) + 1];
		strcpy_s(memory_type, strlen(ram.memory_type) + 1, ram.memory_type);
	}
	else memory_type = nullptr;
}

RAM::~RAM()
{
	if (name != nullptr) delete[]name;
	if (memory_type != nullptr) delete[]memory_type;
}

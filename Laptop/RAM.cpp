#include "RAM.h"
#include <iostream>
using namespace std;

RAM::RAM(const char* Name, int mem, int clock, const char* type): memory(mem), clock_frequency(clock)
{
	if (Name) {
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}
	else name = nullptr;
	if (type) {
		memory_type = new char[strlen(type) + 1];
		strcpy_s(memory_type, strlen(type) + 1, type);
	}
	else type = nullptr;
}

void RAM::set_RAM_name(const char* Name)
{
	if (name)
		delete[] name;

	if (!Name)
	{
		name = nullptr;
		return;
	}

	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}


void RAM::set_RAM_memory(int mem)
{
	if (mem < 0) mem = 0;
	memory = mem;
}

void RAM::set_RAM_clock_frequency(int clock)
{
	if (clock < 0) clock = 0;
	clock_frequency = clock;
}

void RAM::set_RAM_memory_type(const char* type)
{
	if (memory_type)
		delete[] memory_type;

	if (!type)
	{
		memory_type = nullptr;
		return;
	}

	memory_type = new char[strlen(type) + 1];
	strcpy_s(memory_type, strlen(type) + 1, type);
}


const char* RAM::get_RAM_name() { return name; }

int RAM::get_RAM_memory() { return memory; }

int RAM::get_RAM_clock_frequency() { return clock_frequency; }

const char* RAM::get_RAM_memory_type() { return memory_type; }

RAM::RAM(const RAM& ram)
	: RAM (ram.name, ram.memory, ram.clock_frequency, ram.memory_type)
{}

RAM::~RAM()
{
	delete[]name;
	delete[]memory_type;
}

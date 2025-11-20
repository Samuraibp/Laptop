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

void RAM::set_RAM_name()
{
	char Name[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(Name, sizeof(Name));
	if (name != nullptr) delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void RAM::set_RAM_memory()
{
	int mem;
	cin >> mem;
	memory = mem;
}

void RAM::set_RAM_clock_frequency()
{
	int clock;
	cin >> clock;
	clock_frequency = clock;
}

void RAM::set_RAM_memory_type()
{
	char type[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(type, sizeof(type));
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

RAM::~RAM()
{
	if (name != nullptr) delete[]name;
	if (memory_type != nullptr) delete[]memory_type;
}

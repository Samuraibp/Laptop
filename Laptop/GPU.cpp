#include "GPU.h"
#include <iostream>
using namespace std;

GPU::GPU(const char* Name, int mem, int clock): memory(mem), clock_frequency(clock)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void GPU::set_GPU_name(const char* Name)
{
	if (name != nullptr) delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void GPU::set_GPU_memory(int mem)
{
	memory = mem;
}

void GPU::set_GPU_clock_frequency(int clock)
{
	clock_frequency = clock;
}

const char* GPU::get_GPU_name()
{
	return name;
}

int GPU::get_GPU_memory()
{
	return memory;
}

int GPU::get_clock_frequency()
{
	return clock_frequency;
}

GPU::GPU(const GPU& gpu)
	: GPU (gpu.name, gpu.memory, gpu.clock_frequency)
{}

GPU::~GPU()
{
	if (name != nullptr) delete[]name;
}

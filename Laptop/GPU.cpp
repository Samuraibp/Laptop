#include "GPU.h"
#include <iostream>
using namespace std;

GPU::GPU(const char* Name, int mem, int clock): memory(mem), clock_frequency(clock)
{
	if (Name) {
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}
	else name = nullptr;
}

void GPU::set_GPU_name(const char* Name)
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

void GPU::set_GPU_memory(int mem)
{
    if (mem < 0) mem = 0;
    memory = mem;
}

void GPU::set_GPU_clock_frequency(int clock)
{
    if (clock < 0) clock = 0;
    clock_frequency = clock;
}

const char* GPU::get_GPU_name() { return name; }

int GPU::get_GPU_memory() { return memory; }

int GPU::get_GPU_clock_frequency() { return clock_frequency; }

GPU::GPU(const GPU& gpu)
	: GPU (gpu.name, gpu.memory, gpu.clock_frequency)
{}

GPU::~GPU() { delete[]name; }

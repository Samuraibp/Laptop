#pragma once
class GPU
{
	char* name;
	int memory;
	int clock_frequency;
public:
	GPU(const char* Name, int mem, int clock);
	void set_GPU_name(const char* Name);
	void set_GPU_memory(int mem);
	void set_clock_frequency(int clock);
	const char* get_GPU_name();
	int get_GPU_memory();
	int get_clock_frequency();
};


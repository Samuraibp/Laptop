#pragma once
class GPU
{
	char* name;
	int memory;
	int clock_frequency;
public:
	GPU(const char* Name, int mem, int clock);
	void set_GPU_name();
	void set_GPU_memory();
	void set_clock_frequency();
	const char* get_GPU_name();
	int get_GPU_memory();
	int get_clock_frequency();
	GPU(const GPU& gpu);
	~GPU();
};


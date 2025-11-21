#pragma once
class RAM
{
	char* name = nullptr;
	int memory;
	int clock_frequency;
	char* memory_type = nullptr;
public:
	RAM(const char* Name, int mem, int clock, const char* type);
	void set_RAM_name();
	void set_RAM_memory();
	void set_RAM_clock_frequency();
	void set_RAM_memory_type();
	const char* get_RAM_name();
	int get_RAM_memory();
	int get_RAM_clock_frequency();
	const char* get_RAM_memory_type();
	RAM(const RAM& ram);
	~RAM();
};


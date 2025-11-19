#pragma once
class SDD
{
	char* name;
	int memory;
public:
	SDD(const char* name, int memory);
	void set_name(const char* Name);
	void set_memory(int Mem);
	const char* get_name();
	int get_memory();
};


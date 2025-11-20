#pragma once
class SDD
{
	char* name;
	int memory;
public:
	SDD(const char* name, int memory);
	void set_SDD_name(const char* Name);
	void set_memory(int Mem);
	const char* get_SDD_name();
	int get_memory();
};


#pragma once
class SDD
{
	char* name = nullptr;
	int memory;
public:
	SDD(const char* name, int memory);
	void set_SDD_name();
	void set_SDD_memory();
	const char* get_SDD_name();
	int get_memory();
	SDD(const SDD& sdd);
	~SDD();
};


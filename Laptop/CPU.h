#pragma once
class CPU
{
private:
	char* name = nullptr;
	int core;
	int flow;
public:
	CPU(const char* Name, int Core, int Flow);
	void set_CPU_name(const char* Name);
	void set_CPU_core(int Core);
	void set_CPU_flow(int Flow);
	const char* get_CPU_name();
	int get_core();
	int get_flow();
	CPU(const CPU &cpu);
	~CPU();
};


#pragma once
class CPU
{
private:
	char* name = nullptr;
	int core;
	int flow;
public:
	CPU(const char* Name, int Core, int Flow);
	void set_CPU_name();
	void set_core();
	void set_flow();
	const char* get_CPU_name();
	int get_core();
	int get_flow();
	CPU(const CPU &cpu);
	~CPU();
};


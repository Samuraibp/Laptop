#pragma once
class CPU
{
private:
	char* name;
	int core;
	int flow;
public:
	CPU(const char* Name, int Core, int Flow);
	void set_name(const char* Name);
	void set_core(int core);
	void set_flow(int flow);
	char* get_name();
	int get_core();
	int get_flow();
};


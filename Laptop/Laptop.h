#pragma once
#include "CPU.h"
#include "SDD.h"
#include "GPU.h"
#include "RAM.h"

class Laptop
{
	char* name = nullptr;
	int price;
	char* color = nullptr;
	CPU* cpu;
	SDD* sdd;
	GPU* gpu;
	RAM* ram;
public:
	Laptop(const char* Name, int prc, const char* Color, CPU* Cpu, SDD* Sdd, GPU* Gpu, RAM* Ram);
	void set_Lap_name();
	void set_Lap_price();
	void set_Lap_color();
	void set_Lap_cpu();
	void set_Lap_sdd();
	void set_Lap_gpu();
	void set_Lap_ram();
	const char* get_Lap_name();
	int get_Lap_price();
	const char* get_Lap_color();
	Laptop(const Laptop& lap);
	~Laptop();
};


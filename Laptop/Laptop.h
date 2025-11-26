#pragma once
#include "CPU.h"
#include "SDD.h"
#include "GPU.h"
#include "RAM.h"

class Laptop
{
	char* name;
	int price;
	char* color;
	CPU* cpu;
	SDD* sdd;
	GPU* gpu;
	RAM* ram;
	static int laptopCount;
public:
	Laptop(const char* Name, int prc, const char* Color, CPU* Cpu, SDD* Sdd, GPU* Gpu, RAM* Ram);
	Laptop();
	const char* get_Lap_color();
	void set_Lap_name();
	void set_Lap_price();
	void set_Lap_color();
	void set_Lap_cpu();
	void set_Lap_sdd();
	void set_Lap_gpu();
	void set_Lap_ram();
	int safeIntInput(const char* msg);
	const char* get_Lap_name();
	int get_Lap_price();
	CPU* get_Lap_cpu();
	SDD* get_Lap_sdd();
	GPU* get_Lap_gpu();
	RAM* get_Lap_ram();
	static int GetlaptopCount();
	Laptop(const Laptop& lap);
	~Laptop();
};


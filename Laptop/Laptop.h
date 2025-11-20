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
	CPU CPU;
	SDD SDD;
	GPU GPU;
	RAM RAM;
public:
	Laptop(const char* Name, int prc, const char* color);
};


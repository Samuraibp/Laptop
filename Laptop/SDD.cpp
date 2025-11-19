#include "SDD.h"
#include <iostream>
using namespace std;

SDD::SDD(const char* Name, int Memory)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	memory = Memory;
}

void SDD::set_memory(int Mem)
{
	memory = Mem;
}

const char* SDD::get_name()
{
	return name;
}

int SDD::get_memory()
{
	return memory;
}
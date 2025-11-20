#include "SDD.h"
#include <iostream>
using namespace std;

SDD::SDD(const char* Name, int Memory)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	memory = Memory;
}

void SDD::set_SDD_name(const char* Name)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void SDD::set_SDD_memory(int Mem)
{
	memory = Mem;
}

const char* SDD::get_SDD_name()
{
	return name;
}

int SDD::get_memory()
{
	return memory;
}
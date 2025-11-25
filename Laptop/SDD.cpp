#include "SDD.h"
#include <iostream>
using namespace std;

SDD::SDD(const char* Name, int Memory): memory(Memory)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void SDD::set_SDD_name(const char* Name)
{
	if (name != nullptr) delete[]name;
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

SDD::SDD(const SDD& sdd): memory(sdd.memory)
{
	if (sdd.name) {
		name = new char[strlen(sdd.name) + 1];
		strcpy_s(name, strlen(sdd.name) + 1, sdd.name);
	}
	else name = nullptr;
}

SDD::~SDD()
{
	if (name != nullptr) delete[]name;
}

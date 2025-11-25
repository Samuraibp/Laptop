#include "SDD.h"
#include <iostream>
using namespace std;

SDD::SDD(const char* Name, int Memory): memory(Memory)
{
	if (Name) {
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}
	else name = nullptr;
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

SDD::SDD(const SDD& sdd)
	: SDD (sdd.name, sdd.memory)
{}

SDD::~SDD()
{
	if (name != nullptr) delete[]name;
}

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
    if (name)
        delete[] name;

    if (!Name)
    {
        name = nullptr;
        return;
    }

    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);
}


void SDD::set_SDD_memory(int mem)
{
    if (mem < 0) mem = 0;
    memory = mem;
}

const char* SDD::get_SDD_name() { return name; }

int SDD::get_memory() {return memory;}

SDD::SDD(const SDD& sdd)
	: SDD (sdd.name, sdd.memory)
{}

SDD::~SDD() { delete[]name; }

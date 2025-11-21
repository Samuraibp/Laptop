#include "Laptop.h"
#include <iostream>
using namespace std;

Laptop::Laptop(const char* Name, int prc, const char* ñolor, CPU* Cpu, SDD* Sdd, GPU* Gpu, RAM* Ram): price(prc), cpu(Cpu), sdd(Sdd), gpu(Gpu), ram(Ram)
{
    name = new char[strlen(Name) + 1];
    strcpy_s(name, strlen(Name) + 1, Name);

    this->color = new char[strlen(color) + 1];
    strcpy_s(this->color, strlen(color) + 1, color);
}

void Laptop::set_Lap_name()
{
	char Name[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(Name, sizeof(Name));
	if (name != nullptr) delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void Laptop::set_Lap_price()
{
	int prc;
	cin >> prc;
	price = prc;
}

void Laptop::set_Lap_color()
{
	char color[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(color, sizeof(color));
	if (this->color != nullptr) delete[]this->color;
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

void Laptop::set_Lap_cpu()
{
    char Name[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(Name, sizeof(Name));

    delete[] cpu->get_CPU_name();
    cpu->set_CPU_name(Name);          

    int Core;
    cin >> Core;
    cpu->set_core(Core);

    int Flow;
    cin >> Flow;
    cpu->set_flow(Flow);
}




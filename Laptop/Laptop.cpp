#include "Laptop.h"
#include <iostream>
using namespace std;

Laptop::Laptop(const char* Name, int prc, const char* Color, CPU* Cpu, SDD* Sdd, GPU* Gpu, RAM* Ram): price(prc), cpu(Cpu), sdd(Sdd), gpu(Gpu), ram(Ram)
{
    if (Name) {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }
    else name = nullptr;

    if (Color) {
        color = new char[strlen(Color) + 1];
        strcpy_s(color, strlen(Color) + 1, Color);
    }
    else color = nullptr;
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

void Laptop::set_Lap_sdd()
{
    char Name[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(Name, sizeof(Name));

    delete[] sdd->get_SDD_name();
    sdd->set_SDD_name(Name);

    int Mem;
    cin >> Mem;
    sdd->set_SDD_memory(Mem);
}

void Laptop::set_Lap_gpu()
{
    char Name[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(Name, sizeof(Name));

    delete[] gpu->get_GPU_name();
    gpu->set_GPU_name(Name);

    int mem;
    cin >> mem;
    gpu->set_GPU_memory(mem);

    int clock;
    cin >> clock;
    gpu->set_GPU_clock_frequency(clock);
}

void Laptop::set_Lap_ram()
{
    char Name[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(Name, sizeof(Name));
    delete[] ram->get_RAM_name();
    gpu->set_GPU_name(Name);

    int mem;
    cin >> mem;
    ram->set_RAM_memory(mem);

    int clock;
    cin >> clock;
    ram->set_RAM_clock_frequency(clock);

    char type[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(type, sizeof(type));
    delete[] ram->get_RAM_memory_type();
    ram->set_RAM_memory_type(type);
}

const char* Laptop::get_Lap_name()
{
    return name;
}

int Laptop::get_Lap_price()
{
    return price;
}

const char* Laptop::get_Lap_color()
{
    return color;
}

Laptop::Laptop(const Laptop& lap)
    : Laptop(
        lap.name,
        lap.price,
        lap.color,
        lap.cpu ? new CPU(*lap.cpu) : nullptr,
        lap.sdd ? new SDD(*lap.sdd) : nullptr,
        lap.gpu ? new GPU(*lap.gpu) : nullptr,
        lap.ram ? new RAM(*lap.ram) : nullptr
    )
{}

Laptop::~Laptop()
{
    if (name != nullptr) delete[]name;
    if (color != nullptr) delete[]color;
    if (cpu != nullptr) delete cpu;
    if (sdd != nullptr) delete sdd;
    if (gpu != nullptr) delete gpu;
    if (ram != nullptr) delete ram;
}

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
    laptopCount++;
}

Laptop::Laptop()
    : Laptop(nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr)
{}

int Laptop::safeIntInput(const char* msg)
{
    int value;
    while (true)
    {
        cout << msg;
        if (cin >> value && value >= 0)
        {
            return value;
        }

        cout << "Invalid input! Enter a positive number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Laptop::set_Lap_name()
{
	char Name[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of Laptop: ";
	cin.getline(Name, sizeof(Name));
	delete[]name;
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
}

void Laptop::set_Lap_price()
{
    cout << "Enter the price of Laptop: ";
    int prc;

    while (true)
    {
        cin >> prc;

        if (cin.fail())
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Enter a number: ";
        }
        else if (prc < 0)
        {
            cout << "Price cannot be negative! Enter again: ";
        }
        else
        {
            break; 
        }
    }
    price = prc;
}


void Laptop::set_Lap_color()
{
    char Color[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the color of Laptop: ";
    cin.getline(Color, sizeof(Color));
    delete[] color;
    color = new char[strlen(Color) + 1];
    strcpy_s(color, strlen(Color) + 1, Color);
}

void Laptop::set_Lap_cpu()
{
    if (!cpu) {
        cpu = new CPU(nullptr, 0, 0);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char Name[100];
    cout << "Enter the name of CPU: ";
    cin.getline(Name, sizeof(Name));
    cpu->set_CPU_name(Name);

    int Core = safeIntInput("Enter the number of cores: ");
    cpu->set_CPU_core(Core);

    int Flow = safeIntInput("Enter the number of flows: ");
    cpu->set_CPU_flow(Flow);
}


void Laptop::set_Lap_sdd()
{
    if (!sdd)
        sdd = new SDD(nullptr, 0);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char Name[100];
    cout << "Enter the name of SDD: ";
    cin.getline(Name, sizeof(Name));
    sdd->set_SDD_name(Name);

    int Mem = safeIntInput("Enter the memory size (GB): ");
    sdd->set_SDD_memory(Mem);
}


void Laptop::set_Lap_gpu()
{
    if (!gpu)
        gpu = new GPU(nullptr, 0, 0);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char Name[100];
    cout << "Enter the name of GPU: ";
    cin.getline(Name, sizeof(Name));
    gpu->set_GPU_name(Name);

    int mem = safeIntInput("Enter GPU memory (GB): ");
    gpu->set_GPU_memory(mem);

    int clock = safeIntInput("Enter GPU clock frequency (MHz): ");
    gpu->set_GPU_clock_frequency(clock);
}


void Laptop::set_Lap_ram()
{
    if (!ram)
        ram = new RAM(nullptr, 0, 0, nullptr);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char Name[100];
    cout << "Enter the name of RAM: ";
    cin.getline(Name, sizeof(Name));
    ram->set_RAM_name(Name);

    int mem = safeIntInput("Enter RAM memory (GB): ");
    ram->set_RAM_memory(mem);

    int clock = safeIntInput("Enter RAM clock frequency (MHz): ");
    ram->set_RAM_clock_frequency(clock);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char type[100];
    cout << "Enter RAM memory type: ";
    cin.getline(type, sizeof(type));
    ram->set_RAM_memory_type(type);
}


const char* Laptop::get_Lap_name() { return name; }

int Laptop::get_Lap_price() { return price; }

const char* Laptop::get_Lap_color() { return color; }

CPU* Laptop::get_Lap_cpu() { 
    cout << "CPU Core: " << cpu->get_CPU_core() << endl;
    cout << "CPU Flow: " << cpu->get_CPU_flow() << endl;
    return cpu;
}

SDD* Laptop::get_Lap_sdd() {
    cout << "SDD Memory: " << sdd->get_memory() << endl;
    return sdd;
}

GPU* Laptop::get_Lap_gpu() {
    cout << "GPU Memory: " << gpu->get_GPU_memory() << endl;
    cout << "GPU Clock frequency: " << gpu->get_GPU_clock_frequency() << endl;
    return gpu;
}

RAM* Laptop::get_Lap_ram() {
    cout << "RAM Memory: " << ram->get_RAM_memory() << endl;
    cout << "RAM Clock frequency: " << ram->get_RAM_clock_frequency() << endl;
    cout << "RAM Memory type: " << ram->get_RAM_memory_type() << endl;
    return ram;
}

int Laptop::laptopCount = 0;

int Laptop::GetlaptopCount() { return laptopCount; }

Laptop::Laptop(const Laptop& lap)
{
    if (lap.name) {
        name = new char[strlen(lap.name) + 1];
        strcpy_s(name, strlen(lap.name) + 1, lap.name);
    }
    else name = nullptr;

    if (lap.color) {
        color = new char[strlen(lap.color) + 1];
        strcpy_s(color, strlen(color) + 1, lap.color);
    }
    else color = nullptr;

    price = lap.price;

    cpu = lap.cpu ? new CPU(*lap.cpu) : nullptr;
    sdd = lap.sdd ? new SDD(*lap.sdd) : nullptr;
    gpu = lap.gpu ? new GPU(*lap.gpu) : nullptr;
    ram = lap.ram ? new RAM(*lap.ram) : nullptr;

    laptopCount++;
}


Laptop::~Laptop()
{
    delete[] name;
    delete[] color;
    delete cpu;
    delete sdd;
    delete gpu;
    delete ram;
    laptopCount--;
}


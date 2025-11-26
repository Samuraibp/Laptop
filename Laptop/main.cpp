#include "Laptop.h"
#include <iostream>
using namespace std;

int main()
{
    const int MAX_LAPTOPS = 100;
    Laptop* laptops[MAX_LAPTOPS] = { nullptr };

    while (true)
    {
        cout << "-----------" << endl;
        cout << "LAPTOP MENU" << endl;
        cout << "-----------" << endl;
        cout << "1. Create and add a Laptop" << endl;
        cout << "2. Change Laptop name" << endl;
        cout << "3. Change Laptop price" << endl;
        cout << "4. Change Laptop color" << endl;
        cout << "5. Change Laptop CPU" << endl;
        cout << "6. Change Laptop SDD" << endl;
        cout << "7. Change Laptop GPU" << endl;
        cout << "8. Change Laptop RAM" << endl;
        cout << "9. Show all Laptops" << endl;
        cout << "10. Get Laptop name" << endl;
        cout << "11. Get Laptop price" << endl;
        cout << "12. Get Laptop color" << endl;
        cout << "13. Get Laptop CPU" << endl;
        cout << "14. Get Laptop SDD" << endl;
        cout << "15. Get Laptop GPU" << endl;
        cout << "16. Get Laptop RAM" << endl;
        cout << "17. Exit" << endl;
        cout << "\nChoose the command: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (Laptop::GetlaptopCount() >= MAX_LAPTOPS) {
                cout << "Maximum number of laptops reached!" << endl;
                continue;
            }
            int index = Laptop::GetlaptopCount();   
            laptops[index] = new Laptop();          

            laptops[index]->set_Lap_name();
            laptops[index]->set_Lap_price();
            laptops[index]->set_Lap_color();
            laptops[index]->set_Lap_cpu();
            laptops[index]->set_Lap_sdd();
            laptops[index]->set_Lap_gpu();
            laptops[index]->set_Lap_ram();

        }
        else if (choice >= 2 && choice <= 8) {
            if (Laptop::GetlaptopCount() == 0) {
                cout << "No laptops available!" << endl;
                continue;
            }

            cout << "Select Laptop index (0 to " << Laptop::GetlaptopCount() - 1 << "): ";
            int index;
            cin >> index;

            if (index < 0 || index >= Laptop::GetlaptopCount()) {
                cout << "Invalid index!" << endl;
                continue;
            }

            switch (choice) {
            case 2: laptops[index]->set_Lap_name(); break;
            case 3: laptops[index]->set_Lap_price(); break;
            case 4: laptops[index]->set_Lap_color(); break;
            case 5: laptops[index]->set_Lap_cpu(); break;
            case 6: laptops[index]->set_Lap_sdd(); break;
            case 7: laptops[index]->set_Lap_gpu(); break;
            case 8: laptops[index]->set_Lap_ram(); break;
            }
        }
        else if (choice == 9) {
            if (Laptop::GetlaptopCount() == 0) {
                cout << "No laptops available!" << endl;
                continue;
            }

            for (int i = 0; i < Laptop::GetlaptopCount(); i++) {
                cout << "\nLaptop " << i + 1 << ":" << endl;
                cout << "Name: " << laptops[i]->get_Lap_name() << endl;
                cout << "Price: " << laptops[i]->get_Lap_price() << endl;
                cout << "Color: " << laptops[i]->get_Lap_color() << endl;

                CPU* cpu = laptops[i]->get_Lap_cpu();
                SDD* sdd = laptops[i]->get_Lap_sdd();
                GPU* gpu = laptops[i]->get_Lap_gpu();
                RAM* ram = laptops[i]->get_Lap_ram();

                if (cpu) cout << "CPU: " << cpu->get_CPU_name() << endl;
                if (sdd) cout << "SDD: " << sdd->get_SDD_name() << endl;
                if (gpu) cout << "GPU: " << gpu->get_GPU_name() << endl;
                if (ram) cout << "RAM: " << ram->get_RAM_name() << endl;

                cout << "-----------------------------" << endl;
            }
        }
        else if (choice >= 10 && choice <= 16) {
            if (Laptop::GetlaptopCount() == 0) {
                cout << "No laptops available!" << endl;
                continue;
            }

            cout << "Select Laptop index (0 to " << Laptop::GetlaptopCount() - 1 << "): ";
            int index;
            cin >> index;

            if (index < 0 || index >= Laptop::GetlaptopCount()) {
                cout << "Invalid index!" << endl;
                continue;
            }

            Laptop* lap = laptops[index];

            switch (choice) {
            case 10: cout << "Name: " << lap->get_Lap_name() << endl; break;
            case 11: cout << "Price: " << lap->get_Lap_price() << endl; break;
            case 12: cout << "Color: " << lap->get_Lap_color() << endl; break;
            case 13: {
                CPU* cpu = lap->get_Lap_cpu();
                if (cpu) cout << "CPU: " << cpu->get_CPU_name() << endl;
                break;
            }
            case 14: {
                SDD* sdd = lap->get_Lap_sdd();
                if (sdd) cout << "SDD: " << sdd->get_SDD_name() << endl;
                break;
            }
            case 15: {
                GPU* gpu = lap->get_Lap_gpu();
                if (gpu) cout << "GPU: " << gpu->get_GPU_name() << endl;
                break;
            }
            case 16: {
                RAM* ram = lap->get_Lap_ram();
                if (ram) cout << "RAM: " << ram->get_RAM_name() << endl;
                break;
            }
            }
        }
        else if (choice == 17) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    for (int i = 0; i < Laptop::GetlaptopCount(); i++) {
        delete laptops[i];
    }
}

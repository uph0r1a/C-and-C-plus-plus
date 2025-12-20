#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct
{
    string PartDescription;
    int NumberofPart;
} Bin;

void AddParts(Bin &bin)
{
    int add;
    cout << "Enter how much part you want to add in the bin: ";
    while (1)
    {
        cin >> add;
        if (add + bin.NumberofPart <= 30 && add > 0)
        {
            cout << "Number of part added successful";
            bin.NumberofPart += add;
            break;
        }
        if (add + bin.NumberofPart > 30)
        {
            cout << "Each bin can only hold 30 parts" << endl
                 << "Re-enter number of part to add: ";
        }
        else
        {
            cout << "Invalid number of adding part" << endl
                 << "Re-enter number of part to add: ";
        }
    }
}

void RemoveParts(Bin &bin)
{
    int remove;
    cout << "Enter how much part you want to remove from the bin: ";
    while (1)
    {
        cin >> remove;
        if (remove > 0 && remove <= bin.NumberofPart)
        {
            cout << "Number of part removed successful";
            bin.NumberofPart -= remove;
            break;
        }
        if (bin.NumberofPart - remove < 0)
        {
            cout << "You cant remove more than the number of parts in the bin" << endl
                 << "Re-enter number of part to remove: ";
        }
        else
        {
            cout << "Invalid number of part" << endl
                 << "Re-enter number of part to remove: ";
        }
    }
}

void InventoryBins(Bin bin[10])
{
    bool flag = true;
    int choice, pickBin, pickFunc;

    do
    {
        cout << "---------------------------------------------------------------------" << endl;
        cout << left << "|" << setw(5) << "Bin" << "|" << setw(30) << "Part Description" << "|" << setw(30) << "Number of Parts in the Bin" << "|" << endl;
        cout << "|-------------------------------------------------------------------|" << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << left << "|" << setw(5) << i + 1 << "|" << setw(30) << bin[i].PartDescription << "|" << setw(30) << bin[i].NumberofPart << "|" << endl;
        }
        cout << "---------------------------------------------------------------------" << endl;

        cout << "1)Select a bin" << endl
             << "2)Quit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Pick a bin: ";
            while (1)
            {
                cin >> pickBin;
                if (pickBin >= 1 && pickBin <= 10)
                {
                    break;
                }
                cout << "No bin exist\nRe-pick a bin: ";
            }
            cout << "Do you want to 1)Add or 2)Remove: ";
            cin >> pickFunc;
            switch (pickFunc)
            {
            case 1:
                AddParts(bin[pickBin - 1]);
                break;
            case 2:
                RemoveParts(bin[pickBin - 1]);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
            break;
        case 2:
            flag = false;
            break;
        default:
            cout << "Invalid choice" << endl
                 << "Re-enter your choice: ";
            break;
        }

    } while (flag);
}

int main(int argc, char const *argv[])
{
    Bin bin[10] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12},
    };
    InventoryBins(bin);
    return 0;
}

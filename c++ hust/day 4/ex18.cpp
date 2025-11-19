#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string population;
    int year = 1900;

    ifstream f("population.txt");

    cout << "PRAIRIEVILLE POPULATION GROWTH" << "\n(each * represents 1,000 people)" << endl;
    while (getline(f, population))
    {
        cout << year << " ";
        for (int i = 0; i < stoi(population) / 100; i++)
        {
            cout << "*";
        }
        if (year == 2000)
        {
            break;
        }

        year += 20;
        cout << "\n";
    }

    f.close();
    return 0;
}
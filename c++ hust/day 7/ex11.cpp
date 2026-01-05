#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void selectionSort(string arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main(int argc, char const *argv[])
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES], line;
    int count = 0;

    ifstream f("files/names.txt");
    if (!f)
    {
        cout << "Cannot open file" << endl;
        return 1;
    }

    while (count < NUM_NAMES && getline(f, line))
    {
        names[count++] = line;
    }

    selectionSort(names, count);

    for (int i = 0; i < count; i++)
    {
        cout << names[i] << endl;
    }

    f.close();
    return 0;
}

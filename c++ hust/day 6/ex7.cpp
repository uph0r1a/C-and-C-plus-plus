#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void number()
{
    float min, max, sum = 0;
    string name;
    cout << "Enter file name: ";
    cin >> name;

    ifstream f1("files/" + name);

    if (!f1)
    {
        cout << "Cannot open file";
        return;
    }

    int count = 0;
    float line;
    while (f1 >> line)
    {
        count++;
    }

    f1.close();
    f1.open("files/" + name);

    if (!f1)
    {
        cout << "Cannot open file";
        return;
    }

    float *arr = new float[count];

    for (int i = 0; i < count; i++)
    {
        f1 >> arr[i];
        if (i == 0)
        {
            min = arr[i];
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
        sum += arr[i];
    }

    ofstream f2("files/numbersoutput.txt");

    f2 << "The lowest number in the array: " << min << endl
       << "The highest number in the array: " << max << endl
       << "The total of the numbers in the array: " << sum << endl
       << "The average of the numbers in the array: " << sum / count;

    delete[] arr;
    f1.close();
    f2.close();
}

int main(int argc, char const *argv[])
{
    number();
    return 0;
}

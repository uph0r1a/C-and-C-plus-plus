#include <iostream>
using namespace std;

void Minmax()
{
    float arr[10];
    float min, max;
    cout << "Enter 10 values into an array: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
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
    }
    cout << "Max: " << max << endl
         << "Min: " << min;
}

int main(int argc, char const *argv[])
{
    Minmax();
    return 0;
}

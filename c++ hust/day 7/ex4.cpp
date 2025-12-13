#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> &acc)
{
    for (int i = 0; i < acc.size() - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < acc.size(); j++)
        {
            if (acc[j] < acc[min])
                min = j;
        }

        int temp = acc[min];
        acc[min] = acc[i];
        acc[i] = temp;
    }

    return acc;
}

bool accValidation(vector<int> acc, int accInput)
{
    int low = 0, high = acc.size();
    for (int i = low; i < high; i++)
    {
        int mid = (high + low) / 2;
        if (accInput == acc[mid])
        {
            return true;
        }
        else if (accInput < acc[mid])
        {
            high = i - 1;
        }
        else
        {
            low = i + 1;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> acc = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int accInput;
    cout << "Enter a number: ";
    cin >> accInput;

    selectionSort(acc);

    if (accValidation(acc, accInput))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}

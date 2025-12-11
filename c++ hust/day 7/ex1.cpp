#include <iostream>
#include <vector>
using namespace std;

bool accValidation(vector<int> acc, int accInput)
{
    for (int i = 0; i < acc.size(); i++)
    {
        if (accInput == acc[i])
        {
            return true;
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

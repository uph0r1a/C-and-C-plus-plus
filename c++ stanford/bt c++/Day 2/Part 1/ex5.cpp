#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const int SIZE = 16;
    vector<int> numbers;

    cout << "Nhap 16 so nguyen cach nhau dau cach:\n> ";
    string line;
    cin.ignore();
    getline(cin, line);

    istringstream iss(line);
    int x;
    while (iss >> x)
        numbers.push_back(x);

    while ((int)numbers.size() < SIZE)
    {
        cout << "Chi co " << numbers.size() << " so. Nhap them: ";
        string extra;
        getline(cin, extra);
        istringstream iss2(extra);
        while (iss2 >> x && (int)numbers.size() < SIZE)
            numbers.push_back(x);
    }

    cout << "\nMa tran 4x4:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << numbers[i];
        if ((i + 1) % 4 == 0)
            cout << "\n";
    }
    return 0;
}

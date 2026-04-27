#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const int ROWS = 4, COLS = 4;
    int arr[ROWS][COLS];

    cout << "Nhap cac phan tu cho mang 4x4:\n";
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            cout << "  arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }

    cout << "\nMang 4x4:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << setw(6) << arr[i][j];
        cout << "\n";
    }

    return 0;
}

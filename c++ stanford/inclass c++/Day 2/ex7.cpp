#include <iostream>
#include <iomanip>
#include <vector>
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

    vector<int> vecDuong, vecAm;
    int tongDuong = 0, tongAm = 0;

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] > 0)
            {
                vecDuong.push_back(arr[i][j]);
                tongDuong += arr[i][j];
            }
            else if (arr[i][j] < 0)
            {
                vecAm.push_back(arr[i][j]);
                tongAm += arr[i][j];
            }
        }

    cout << "\nPhan tu duong (" << vecDuong.size() << " phan tu): ";
    for (int v : vecDuong)
        cout << v << "  ";
    cout << "\nTong so duong: " << tongDuong << "\n";

    cout << "\nPhan tu am (" << vecAm.size() << " phan tu): ";
    for (int v : vecAm)
        cout << v << "  ";
    cout << "\nTong so am: " << tongAm << "\n";

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[3];
    cout << "Nhap 3 so nguyen: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "so " << (i + 1) << ": ";
        cin >> arr[i];
    }

    sort(arr, arr + 3);

    cout << "Tang dan: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\nGiam dan: ";
    for (int i = 2; i >= 0; i--)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}

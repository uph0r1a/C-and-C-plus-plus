#include <iostream>
using namespace std;

void swap(float &a, float &b)
{
    float tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[])
{
    const int MAX = 20;
    float arr[MAX];
    int N = 0;

    do
    {
        cout << "Nhap so phan tu N (1 - " << MAX << "): ";
        cin >> N;
        if (N < 1 || N > MAX)
            cout << "N phai nam trong khoang 1 den " << MAX << ". Nhap lai.\n";
    } while (N < 1 || N > MAX);

    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < N; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }

    cout << "\nDay sap xep tang dan: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << "  ";
    cout << "\n";

    cout << "Day sap xep giam dan: ";
    for (int i = N - 1; i >= 0; i--)
        cout << arr[i] << "  ";
    cout << "\n";

    return 0;
}

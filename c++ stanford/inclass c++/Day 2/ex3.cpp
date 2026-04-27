#include <iostream>
using namespace std;

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

    float maxVal = arr[0], minVal = arr[0];
    int maxIdx = 0, minIdx = 0;

    for (int i = 1; i < N; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
            maxIdx = i;
        }
        if (arr[i] < minVal)
        {
            minVal = arr[i];
            minIdx = i;
        }
    }

    cout << "\nGia tri lon nhat: " << maxVal << " (vi tri " << maxIdx + 1 << ")\n";
    cout << "Gia tri nho nhat: " << minVal << " (vi tri " << minIdx + 1 << ")\n";

    return 0;
}

#include <iostream>
using namespace std;

void traoDoi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool hoaned = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                traoDoi(arr[j], arr[j + 1]);
                hoaned = true;
            }
        }
        if (!hoaned)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            traoDoi(arr[i], arr[minIdx]);
        }
    }
}

void inMang(const char *label, int arr[], int n)
{
    cout << label << ": ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int x = 42, y = 99;
    cout << "Truoc trao doi: x = " << x << ", y = " << y << endl;
    traoDoi(x, y);
    cout << "Sau trao doi : x = " << x << ", y = " << y << endl;
    cout << endl;

    int arr1[] = {7, 2, 9, 1, 5, 8, 3, 6, 4};
    int arr2[] = {7, 2, 9, 1, 5, 8, 3, 6, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    inMang("Mang ban dau", arr1, n);

    bubbleSort(arr1, n);
    inMang("Bubble Sort", arr1, n);

    selectionSort(arr2, n);
    inMang("Selection Sort", arr2, n);

    cout << endl;
    cout << "Nhap so phan tu: ";
    int m;
    cin >> m;
    int *arr3 = new int[m];
    cout << "Nhap " << m << " phan tu: ";
    for (int i = 0; i < m; i++)
        cin >> arr3[i];

    inMang("Truoc sap xep", arr3, m);
    bubbleSort(arr3, m);
    inMang("Sau sap xep  ", arr3, m);

    delete[] arr3;
    return 0;
}

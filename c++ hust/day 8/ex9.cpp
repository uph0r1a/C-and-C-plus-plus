#include <iostream>
using namespace std;

double findMedian(int *arr, int size)
{
    if (size % 2 != 0)
    {
        return *(arr + size / 2);
    }
    else
    {
        int mid1 = *(arr + (size / 2) - 1);
        int mid2 = *(arr + (size / 2));
        return (mid1 + mid2) / 2.0;
    }
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 3, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Median of arr1: " << findMedian(arr1, size1) << endl;

    return 0;
}

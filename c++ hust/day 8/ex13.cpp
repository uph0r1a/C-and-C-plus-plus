#include <iostream>
using namespace std;

int findMode(int *arr, int size)
{
    int mode = -1;
    int maxCount = 1;

    for (int i = 0; i < size; i++)
    {
        int count = 1;

        for (int j = i + 1; j < size; j++)
        {
            if (*(arr + i) == *(arr + j))
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = *(arr + i);
        }
    }

    return mode;
}

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
    int numberOfStudent, mode;
    double median, sum = 0;
    cout << "Enter the number of students were surveyed: ";
    while (1)
    {
        cin >> numberOfStudent;
        if (numberOfStudent >= 0)
        {
            break;
        }
        cout << "The number of students were surveyed cannot be negative\nRe-enter the number of students were surveyed: ";
    }

    int *student = new int[numberOfStudent];

    for (int i = 0; i < numberOfStudent; i++)
    {
        cout << "Enter the number of movie student " << i + 1 << " saw: ";
        while (1)
        {
            cin >> student[i];
            if (student[i] >= 0)
            {
                break;
            }
            cout << "The number of movie student " << i + 1 << " saw cannot be negative\nRe-enter the number of movie student " << i + 1 << " saw: ";
        }

        sum += student[i];
    }
    mode = findMode(student, numberOfStudent);
    median = findMedian(student, numberOfStudent);

    cout << "Average: " << sum / numberOfStudent << endl
         << "Median: " << median << endl
         << "Mode: " << mode << endl;

    return 0;
}

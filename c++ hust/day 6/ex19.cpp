#include <iostream>
using namespace std;

float getTotal(float arr[3][4])
{
    float sum = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

float getAverage(float arr[3][4])
{
    float sum = getTotal(arr);

    return sum / (3 * 4);
}

float getRowTotal(float arr[3][4], int row)
{
    float sum = 0;

    if (row >= 3)
    {
        cout << "Row didnt exist\n";
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        sum += arr[row][i];
    }

    return sum;
}

float getColumnTotal(float arr[3][4], int column)
{
    float sum = 0;

    if (column >= 4)
    {
        cout << "Column didnt exist\n";
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        sum += arr[i][column];
    }

    return sum;
}

float getHighestInRow(float arr[3][4], int row)
{
    float max;

    if (row >= 3)
    {
        cout << "Row didnt exist\n";
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {

        if (i == 0)
        {
            max = arr[row][i];
        }

        if (arr[row][i] > max)
        {
            max = arr[row][i];
        }
    }

    return max;
}

float getLowestInRow(float arr[3][4], int row)
{
    float min;

    if (row >= 4)
    {
        cout << "Row didnt exist\n";
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {

        if (i == 0)
        {
            min = arr[row][i];
        }

        if (arr[row][i] < min)
        {
            min = arr[row][i];
        }
    }

    return min;
}

int main(int argc, char const *argv[])
{
    float arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    int row = 2, column = 3;

    cout
        << getTotal(arr) << endl
        << getAverage(arr) << endl
        << getRowTotal(arr, row) << endl
        << getColumnTotal(arr, column) << endl
        << getHighestInRow(arr, row) << endl
        << getLowestInRow(arr, row);
    return 0;
}

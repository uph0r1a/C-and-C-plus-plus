#include <iostream>
using namespace std;

bool isLoShu(float arr[3][3])
{
    float sum_row = 0, sub_sum;
    for (int i = 0; i < 3; i++)
    {
        sub_sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sub_sum += arr[i][j];
        }
        if (i == 0)
        {
            sum_row = sub_sum;
            continue;
        }
        if (sub_sum != sum_row)
        {
            return false;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        sub_sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sub_sum += arr[i][j];
        }
        if (sub_sum != sum_row)
        {
            return false;
        }
    }

    sub_sum = 0;
    for (int i = 0; i < 3; i++)
    {

        sub_sum += arr[i][i];
    }

    if (sub_sum != sum_row)
    {
        return false;
    }

    sub_sum = 0;
    for (int i = 0, j = 2; i < 3; i++, j--)
    {
        sub_sum += arr[i][j];
    }
    if (sub_sum != sum_row)
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    float arr[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}};

    if (isLoShu(arr))
    {
        cout << "The array is a Lo Shu Magic Square";
    }
    else
    {
        cout << "The array is not a Lo Shu Magic Square";
    }

    return 0;
}

#include <iostream>
using namespace std;

bool isLoShu(float arr[3][3])
{
    float sum_row = 0;
    for (int i = 0; i < 3; i++)
    {
        float sub_sum = 0;
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
        for (int i = 0; i < 3; i++)
        {
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{

    return 0;
}

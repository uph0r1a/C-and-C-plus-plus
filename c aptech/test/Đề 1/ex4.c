#include <stdio.h>

float sum(float arr[3][3]){
    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

float max(float arr[3][3]){
    float max = arr[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
        
    }
    return max;
}

int main(int argc, char const *argv[])
{
    float arr[3][3];
    printf("Enter a 3x3 matrix: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }

    printf("Sum of all elements: %.2f\n",sum(arr));
    printf("Largest element: %.2f",max(arr));

    return 0;
}

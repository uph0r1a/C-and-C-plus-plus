#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ages[5];
    printf("Please enter the ages of 5 students: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Student %d: ", i + 1);
        while (1)
        {
            scanf("%d", &ages[i]);
            if (ages[i] < 5 || ages[i] > 18)
            {
                printf("Age must be greater than 5 and less than 18.\n");
                printf("Please enter the age for Student %d again: ", i + 1);
            }
            else
            {
                break;
            }
            
        }
    }

    int min = ages[0];
    for (int i = 1; i < 5; i++)
    {
        if (min > ages[i])
        {
            min = ages[i];
        }
    }
    printf("Minimum age: %d\n", min);

    int max = ages[0];
    for (int i = 1; i < 5; i++)
    {
        if (max < ages[i])
        {
            max = ages[i];
        }
    }
    printf("Maximum age: %d\n", max);

    int tong = 0;
    float average;
    for (int i = 0; i < 5; i++)
    {
        tong += ages[i];
    }
    average = tong / 5.0;
    printf("Average age: %.2f", average);

    return 0;
}

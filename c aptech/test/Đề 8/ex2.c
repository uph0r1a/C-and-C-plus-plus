#include <stdio.h>

int main(int argc, char const *argv[])
{
    float number[5];
    printf("Input 5 numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("number %d: ", i + 1);
        scanf("%f", &number[i]);
    }

    printf("Reverse list number you inputted: ");
    for (int i = 4; i >= 0; i--)
    {
        printf("%.2f ", number[i]);
    }

    return 0;
}

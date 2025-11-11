#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;

    while (1)
    {
        printf("Enter three integers: ");
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);

        if (a < 0 || b < 0 || c < 0)
        {
            printf("Error: All numbers must be positive.\n");
        }
        else
        {
            printf("Average: %f", (float)(a + b + c) / 3);
            break;
        }
    }
    return 0;
}

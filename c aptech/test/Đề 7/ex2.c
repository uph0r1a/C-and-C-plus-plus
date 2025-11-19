#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float a, b, c, d, e, result;

    printf("Enter value for a: ");
    scanf("%f", &a);
    printf("Enter value for b: ");
    scanf("%f", &b);
    printf("Enter value for c: ");
    scanf("%f", &c);
    printf("Enter value for d: ");
    scanf("%f", &d);
    printf("Enter value for e: ");
    while (1)
    {
        scanf("%f", &e);
        if (e != 0)
        {
            break;
        }
        printf("e must not equal to 0\n");
        printf("Re-enter value for e: ");
    }

    result = pow((a + b), c) - (d / e);
    printf("Result: %.2f", result);
    return 0;
}

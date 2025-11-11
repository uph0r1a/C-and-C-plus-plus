#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("Enter an integer: ");
    scanf("%d",&a);

    if (a > 0)
    {
        printf("Positive");
    }
    else if (a < 0)
    {
        printf("Negative");
    }
    else
    {
        printf("Zero");
    }
    
    return 0;
}

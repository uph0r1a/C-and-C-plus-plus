#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    const float pi = 3.14;
    int choice, flag = 1;

    printf("Copy\n");
    printf("1. Calculate the area of a rectangle\n");
    printf("2. Calculate the area of a circle\n");
    printf("3. Calculate the area of a triangle\n");
    printf("4. Quit\n");

    while (flag)
    {
        printf("Select a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            float width, length;
            printf("Enter the width: ");
            scanf("%f", &width);
            printf("Enter the length: ");
            scanf("%f", &length);
            printf("The area of a rectangle: %.2f\n", width * length);
            break;
        case 2:
            float radius;
            printf("Enter the radius: ");
            scanf("%f", &radius);
            printf("The area of a circle: %.2f\n", pi * pow(radius, 2));
            break;
        case 3:
            float height, base;
            printf("Enter the height: ");
            scanf("%f", &height);
            printf("Enter the base: ");
            scanf("%f", &base);
            printf("The area of a triangle: %.2f\n", (width * length) / 2);
            break;
        case 4:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

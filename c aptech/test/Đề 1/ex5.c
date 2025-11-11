#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int number;

    printf("Enter the number of elements: ");
    scanf("%d", &number);

    int *interger = malloc(number * sizeof(int));

    if (interger == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter %d integers: ", number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &interger[i]);
    }

    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            if (interger[j] > interger[j + 1])
            {
                int temp = interger[j];
                interger[j] = interger[j + 1];
                interger[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < number; i++)
    {
        printf("%d ", interger[i]);
    }

    free(interger);
    interger = NULL;
    return 0;
}

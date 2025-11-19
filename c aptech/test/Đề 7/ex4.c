#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int number_of_element;
    int *array = malloc(number_of_element * sizeof(int));

    printf("Enter the number of elements: ");
    scanf("%d", &number_of_element);

    if (array == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter %d intergers: ", number_of_element);
    for (int i = 0; i < number_of_element; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < number_of_element - 1; i++)
    {
        for (int j = 0; j < number_of_element - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = number_of_element - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}

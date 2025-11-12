#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char K[1000], V[1000];

    printf("Nhap xau K: ");
    fgets(K, 1000, stdin);
    K[strcspn(K, "\n")] = 0;

    printf("Nhap xau V: ");
    fgets(V, 1000, stdin);
    V[strcspn(V, "\n")] = 0;

    char *check = strstr(K, V);
    if (check == NULL)
    {
        printf("K ko chua V\n");
    }
    else
    {
        printf("K chua V\n");
    }

    return 0;
}
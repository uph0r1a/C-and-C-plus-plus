#include <stdio.h>

int main(int argc, char const *argv[]){
    FILE *f;
    f = fopen("output.txt", "w");
    char s[100] = "kdjaksjd";
    fprintf(f,"%d %f %c %s\n", 83848, 2.2, '+', s);
    fclose(f);
    return 0;
}
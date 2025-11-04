#include <stdio.h>

int main()
{
	char d[100];
	FILE *f;
	int i = 0;

	f = fopen("nhanvien.txt", "r");
	while (!feof(f))
	{
		i = fgetc(f);
		printf("%c", i);
	}

	fclose(f);
}
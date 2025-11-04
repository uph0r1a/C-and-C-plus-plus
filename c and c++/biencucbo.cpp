#include <stdio.h>

int i; // bien toan cuc
void in(void);
void in(void)
{
	int k;
	k = i * 10 + 3;
	printf("gia tri cua bien k su dung trong ham con %d\n", k);
}

int main()
{
	i = 5;
	in();
	printf("Gia tri cua bien k su dung trong than ham chinh %d", k);
}
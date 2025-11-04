#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	int len;
	char a[5] = ""; // Bat buoc phai khoi tao gia tri cho bien
	a[0] = 't';
	len = strlen(a);
	printf("Do dai chuoi a %d \n", len);
	//	printf("a[0]:%c a[1]:%c",a[0],a[1]);
	if (a[0] != ' ')
	{
		printf("Dung roi !");
	}
	else
	{
		printf("Khong phai dau cach ma la kt :%c \n", a[0]);
	}
	//	a[len]='x';
	a[] = a[] + 'x';
	printf("Xau moi la %s", a);
}
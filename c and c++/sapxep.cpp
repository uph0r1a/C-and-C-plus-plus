#include <stdio.h>

void hoanvi(int *a, int *b);
void sap_xep(int mangcansx[], int ktmang);
void hoanvi(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void sap_xep(int mangcansx[], int ktmang)
{
	int j = 0;
	int i;
	do
	{
		for (i = j + 1; i < ktmang; i++)
		{
			if (mangcansx[i] > mangcansx[j])
				hoanvi(&mangcansx[i], &mangcansx[j]);
		}
		j++;
	} while (j < ktmang - 1);
}

int main()
{
	int a[10];
	int so_hang;
	int so_pt;

	// Nhap du lieu cho mang
	printf("Ban muon nhap bao nhieu so: ");
	scanf("%d", &so_pt);

	for (so_hang = 0; so_hang <= so_pt - 1; so_hang++)
	{
		printf("Hay nhap so thu %d :", so_hang + 1);
		scanf("%d", &a[so_hang]);
	}
	// Sap xep du lieu theo thu tu tang dan
	sap_xep(a, so_pt);
	// In du lieu sau khi sap xep
	for (int k = 0; k < so_pt; k++)
	{
		printf("%d ", a[k]);
	}
}
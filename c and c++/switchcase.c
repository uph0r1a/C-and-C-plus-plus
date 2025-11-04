#include <stdio.h>
int main()
{
	int thu;
	char phuongan;
	printf("Chao mung ban den voi chuong trinh cua chung toi !");
	do
	{
		printf("\n Ban muon biet ngay thu may trong tuan: ");
		scanf("%d", &thu);
		switch (thu)
		{
		case 2:
		{
			printf("MONDAY \n");
			break;
		}
		case 3:
		{
			printf("TUESDAY \n");
			break;
		}
		case 4:
		{
			printf("WEDNESDAY \n");
			break;
		}
		case 5:
		{
			printf("THURSDAY \n");
			break;
		}
		case 6:
		{
			printf("FRIDAY \n");
			break;
		}
		case 7:
		{
			printf("SATURDAY \n");
			break;
		}
		case 8:
		{
			printf("SUNDAY \n");
			break;
		}
		default:
			printf("khong co ngay nay \n");
		}
		printf("Co tiep tuc khong? - C/K \n");
		phuongan = getch();
	} while (phuongan == 'C' || phuongan == 'c');
	printf("\n Tam biet");
}

#include <stdio.h>
#include <conio.h>
int main()
{
	int thu;
	char phuongan;
	/* gan gia tri cho bien Phuongan de nhay vao vong lap while */
	phuongan = 'C';
	printf("Chao mung ban den voi chuong trinh cua chung toi ! ");
	while (phuongan == 'C' || phuongan == 'c')
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
		phuongan = getch(); /*nhan gia tri cho bien phuongan de tiep tuc vong lap while hay khong*/
	}
	printf("\n Tam biet");
}
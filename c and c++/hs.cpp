#include <stdio.h>
#include <string.h>
struct hoc_sinh
{
	char ten[30];
	int nam_sinh;
	float diem;
};

int main()
{
	int stt;
	char phuongan;

	struct hoc_sinh s1;
	strcpy(s1.ten, "Thai Duc Tri");
	s1.nam_sinh = 2006;
	s1.diem = 9.5;

	struct hoc_sinh s2;
	strcpy(s2.ten, "Thai Tri Dung");
	s2.nam_sinh = 2009;
	s2.diem = 9.0;

	struct hoc_sinh s3;
	strcpy(s3.ten, "Thai Trong Nghia");
	s3.nam_sinh = 1969;
	s3.diem = 10.0;

	struct hoc_sinh s4;
	strcpy(s4.ten, "Hoang Thi Thanh Giang");
	s4.nam_sinh = 1975;
	s4.diem = 9.75;

	do
	{
		printf("\nBan muon biet hoc sinh nao: ");
		scanf("%d", &stt);
		switch (stt)
		{
		case 1:
			printf("Ten: %s", s1.ten);
			printf("\nNam sinh: %d", s1.nam_sinh);
			printf("\nDiem: %.1f", s1.diem);
			break;

		case 2:
			printf("Ten: %s", s2.ten);
			printf("\nNam sinh: %d", s2.nam_sinh);
			printf("\nDiem: %.1f", s2.diem);
			break;

		case 3:
			printf("Ten: %s", s3.ten);
			printf("\nNam sinh: %d", s3.nam_sinh);
			printf("\nDiem: %.1f", s3.diem);
			break;

		case 4:
			printf("Ten: %s", s4.ten);
			printf("\nNam sinh: %d", s4.nam_sinh);
			printf("\nDiem: %.1f", s4.diem);
			break;

		default:
			printf("khong hoc sinh nao co stt nay");
		}
		printf("\nCo tiep tuc khong? - C/K \n");
		getchar();
		phuongan = getchar();
	} while (phuongan == 'C' || phuongan == 'c');
	printf("\n Tam biet");
}

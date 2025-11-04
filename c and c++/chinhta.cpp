#include <stdio.h>
#include <ctype.h>
#include <string.h>

void dichchuyenStr(char mangkt[100], int vtden, int vtktchuyen);

void dichchuyenStr(char mangkt[100], int vtden, int vtktchuyen)
{
	int dodai = strlen(mangkt);
	int j;
	int k = vtktchuyen - vtden; /* so dau cach can bo*/

	// dich chuyen phan con lai cua xau
	for (j = vtktchuyen; j <= dodai; j++)
	{
		mangkt[j - k] = mangkt[j];
	}

	// loai bo vi tri thua o cuoi xau
	for (j = dodai - k; j < dodai; j++)
	{
		mangkt[j] = '\0';
	}
}

int main()
{
	char cau[100];
	int i = 0;
	int chisoden = 0;
	int dodai;
	int ktcuoi;
	int k;

	printf("Hay nhap cau can kiem tra chinh ta: ");
	fgets(cau, sizeof(cau), stdin);

	// kiem tra ki tu trong dau cau
	while (cau[i] == ' ')
	{
		i++;
	}

	// dich chuyen ca cau ve vi tri ki tu trong dau tien
	if (i > 0)
	{
		dichchuyenStr(cau, chisoden, i);
	}

	// Viet hoa ky tu dau
	if (cau[0] != '\0' && isalpha(cau[0]))
	{
		cau[0] = toupper(cau[0]);
	}

	// xoa duoi
	dodai = strlen(cau);

	if (cau[dodai - 1] = ' ')
	{
		for (i = 0; i < dodai - 1; i++)
		{
			if (isalnum(cau[i]))
			{
				ktcuoi = i;
			}
		}
		for (i = ktcuoi + 1; i < dodai - 1; i++)
			cau[i] = '\0';
	}

	// xoa khoang trong giua cau
	i = 0;
	while (cau[i] != '\0')
	{
		// Kiem tra cau co nhieu hon 1 khoang trong thi dem tiep
		if (cau[i] == ' ' && cau[i + 1] == ' ')
		{
			k = i;
			// xac dinh chi so cua phan tu can chuyen
			while (cau[k] == ' ')
			{
				k++;
			}
			// dich chuyen khi vi tri can dich nhieu hon vi tri chuyen den 2 khoang cach
			if (k > i + 1)
			{
				dichchuyenStr(cau, i + 1, k);
			}
		}
		else
		{
			i++;
		}
	}
	printf("Sau khi kiem tra va sua chinh ta: %s\n ", cau);
}
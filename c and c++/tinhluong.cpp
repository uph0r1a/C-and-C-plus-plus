#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nhanvien
{
    int stt;
    char ten[30];
    int bacluong;
};

size_t length_before_newline(const char *str)
{
    size_t length = 0;
    while (str[length] != '\n' && str[length] != '\0')
    {
        length++;
    }
    return length;
}

void parse_line(const char *line, struct nhanvien *nv)
{
    size_t len = length_before_newline(line);

    sscanf(line, "%d %*s %*s %*s %d", &nv->stt, &nv->bacluong);

    int name_start = 2;
    int name_end = len - 2;

    strncpy(nv->ten, line + name_start, name_end - name_start);
    nv->ten[name_end - name_start] = '\0';
}

int tinhluong(int bacluong)
{
    return 3500000 + (bacluong - 1) * 1000000;
}

int main()
{
    char d[256];
    struct nhanvien nv;
    FILE *f;
    int input_stt;

    f = fopen("nhanvien.txt", "r");

    while (fgets(d, sizeof(d), f) != NULL)
    {
        parse_line(d, &nv);
    }

    fclose(f);

    printf("Hay nhap stt: ");
    scanf("%d", &input_stt);

    f = fopen("nhanvien.txt", "r");

    while (fgets(d, sizeof(d), f) != NULL)
    {
        parse_line(d, &nv);

        if (nv.stt == input_stt)
        {
            int luong = tinhluong(nv.bacluong);
            printf("Ten: %s, Luong: %.d\n", nv.ten, luong);
            break;
        }
        else
        {
            printf("Stt cua nhan vien nay khong ton tai. Hay nhap lai stt");
            break;
        }
    }

    fclose(f);
}

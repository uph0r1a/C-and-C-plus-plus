// Bài 1. Nhập vào một chuỗi, sau đó in chuỗi đó ra màn hình.
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    printf("Nhap xau: ");
    fgets(c, 1000, stdin);
    printf("Xau vua nhap : %s\n", c);
    return 0;
}
// Bài 2. Nhập vào một chuỗi, sau đó in hoa/in thường chuỗi đó ra màn hình.
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    int chon;
    printf("Nhap xau: ");
    fgets(c, 1000, stdin);
loop:
    printf("In thuong(1) hay hoa(2): ");
    scanf("%d", &chon);

    if (chon == 1)
    {
        printf("%s", strlwr(c));
    }
    else if (chon == 2)
    {
        printf("%s", strupr(c));
    }
    else
    {
        printf("Nhap sai\n");
        goto loop;
    }
    return 0;
}
// Bài 3. Nhập vào một chuỗi, sau đó in ra màn hình chuỗi đảo ngược ra màn hình.
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    printf("Nhap xau: ");
    fgets(c, 1000, stdin);

    for (int i = strlen(c); i >= 0; i--)
    {
        printf("%c", c[i]);
    }
    return 0;
}
// Bài 4. Nhập vào một chuỗi, sau đó in ra số lượng ký tự là nguyên âm/phụ âm ra màn hình.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    int nguyenam = 0, phuam = 0;

    printf("Nhap xau: ");
    fgets(c, 1000, stdin);

    for (int i = 0; i < strlen(c); i++)
    {
        char ch = tolower(c[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            nguyenam++;
        }
        else if (isalpha(ch))
        {
            phuam++;
        }
    }

    printf("Nguyen am: %d\nPhu am: %d\n", nguyenam, phuam);

    return 0;
}
// Bài 5. Nhập vào chuỗi K và chuỗi V. Kiểm tra xem chuỗi K có chứa V không? (hàm strstr)
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char K[1000], V[1000];

    printf("Nhap xau K: ");
    fgets(K, 1000, stdin);
    K[strcspn(K, "\n")] = 0;

    printf("Nhap xau V: ");
    fgets(V, 1000, stdin);
    V[strcspn(V, "\n")] = 0;

    char *check = strstr(K, V);
    if (check == NULL)
    {
        printf("K ko chua V\n");
    }
    else
    {
        printf("K chua V\n");
    }

    return 0;
}
// Bài 6. Nhập vào một chuỗi, sau đó in ra tần suất xuất hiện của các ký tự.
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c[1000];
    int tansuat[256] = {0};
    int length;

    printf("Nhap xau: ");
    fgets(c, 1000, stdin);

    c[strcspn(c, "\n")] = 0;

    length = strlen(c);

    for (int i = 0; i < length; i++)
    {
        unsigned char ch = (unsigned char)c[i];
        tansuat[ch]++;
    }

    printf("Tan suat xuat hien cac ky tu:\n");
    for (int i = 0; i < 256; i++)
    {
        if (tansuat[i] > 0)
        {
            printf("Ky tu '%c' xuat hien %d lan\n", i, tansuat[i]);
        }
    }

    return 0;
}
// Bài 7. Nhập vào một chuỗi, xóa các khoảng trắng thừa sau đó in ra màn hình.
// VD: _ _Luong_ _ _Trung_Hieu_ _ _ -> Luong_Trung_Hieu
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_separator(char c)
{
    return c == ' ' || c == '_' || c == '-';
}

int main(int argc, char const *argv[])
{
    char input[1000];
    char output[1000];
    int i = 0, j = 0;

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    while (is_separator(input[i]))
        i++;

    int word_started = 0;

    while (input[i] != '\0')
    {
        if (is_separator(input[i]))
        {
            if (word_started)
            {
                output[j++] = '_';
                word_started = 0;
            }
            while (is_separator(input[i]))
                i++;
        }
        else
        {
            output[j++] = input[i++];
            word_started = 1;
        }
    }

    if (j > 0 && output[j - 1] == '_')
        j--;

    output[j] = '\0';

    printf("Ket qua: %s\n", output);

    return 0;
}
// Bài 8. Chuẩn hóa tên. Ví dụ "   nguYEN   Thuy  linH   " => "Nguyen Thuy Linh".
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoaTen(char *s)
{
    char temp[1000];
    int i = 0, j = 0;

    while (isspace(s[i]))
        i++;

    int word_started = 0;

    while (s[i] != '\0')
    {
        if (isspace(s[i]))
        {
            if (word_started)
            {
                temp[j++] = ' ';
                word_started = 0;
            }
            while (isspace(s[i]))
                i++;
        }
        else
        {
            temp[j++] = tolower(s[i++]);
            word_started = 1;
        }
    }

    if (j > 0 && temp[j - 1] == ' ')
        j--;

    temp[j] = '\0';

    int len = strlen(temp);
    int first = 1;
    for (i = 0; i < len; i++)
    {
        if (first && isalpha(temp[i]))
        {
            temp[i] = toupper(temp[i]);
            first = 0;
        }
        else if (temp[i] == ' ')
        {
            first = 1;
        }
    }

    strcpy(s, temp);
}

int main(int argc, char const *argv[])
{
    char name[1000];

    printf("Nhap ten: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    chuanHoaTen(name);

    printf("Ten chuan hoa: %s\n", name);

    return 0;
}
// Bài 9. Chuẩn hóa tên (in tên trước, họ đệm sau). Ví dụ "tran    VaN  Toan" => "Toan Tran Van". (strtok)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoaTu(char *s)
{
    if (strlen(s) > 0)
    {
        s[0] = toupper(s[0]);
        for (int i = 1; s[i]; i++)
        {
            s[i] = tolower(s[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    char input[1000];
    char *words[100];
    int count = 0;

    printf("Nhap ho ten: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " \t");
    while (token != NULL)
    {
        chuanHoaTu(token);
        words[count++] = token;
        token = strtok(NULL, " \t");
    }

    if (count == 0)
    {
        printf("Khong co tu nao!\n");
        return 0;
    }

    printf("Ten chuan hoa: %s", words[count - 1]);

    for (int i = 0; i < count - 1; i++)
    {
        printf(" %s", words[i]);
    }

    printf("\n");

    return 0;
}
// Bài 10. Cấp email cho sinh viên. Ví dụ: người dùng nhập “Nguyen Van Minh” → Email: minhnv@aptech.com.vn (strtok)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerStr(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]);
    }
}

int main(int argc, char const *argv[])
{
    char input[1000];
    char *words[100];
    int count = 0;

    printf("Nhap ho ten: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " \t");
    while (token != NULL)
    {
        words[count++] = token;
        token = strtok(NULL, " \t");
    }

    if (count == 0)
    {
        printf("Khong co ten!\n");
        return 0;
    }

    char email[100] = "";
    char ten[50];
    strcpy(ten, words[count - 1]);
    toLowerStr(ten);
    strcat(email, ten);

    for (int i = 0; i < count - 1; i++)
    {
        char ch = tolower(words[i][0]);
        char str[2] = {ch, '\0'};
        strcat(email, str);
    }

    strcat(email, "@aptech.com.vn");

    printf("Email: %s\n", email);

    return 0;
}
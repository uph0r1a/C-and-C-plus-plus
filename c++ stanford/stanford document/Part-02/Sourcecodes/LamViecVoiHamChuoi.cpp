#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
    /*
    //Khai báo mảng kí tự
    char s[10], t[10];

    //Gán giá trị cho mảng
    strcpy_s(t, "Stanford");

    //Gán mảng t cho s
    //strcpy_s(s, t);

    //Lấy 5 kí tự của t gán cho s
    strncpy_s(s, t, 5);

    //Nối thêm kí tự vào mảng chuỗi
    strcat_s(s, "Ord");

    //So sánh 2 chuỗi
    int ketQua = strcmp(s, t);

    //So sánh 5 kí tự đầu tiên
    ketQua = strncmp(s, t, 5);

    //So sánh không phân biệt hoa thường
    ketQua = strcmpi(s, t);

    cout <<"Ket qua so sanh la: "<<ketQua<<endl;

    cout <<"Gia tri mang "<<s<<" to "<<t<<endl;

    cout <<"In cac ki tu trong mang ki tu: "<<endl;

    for(int i = 0; i < 8; i++)
    {
        cout <<t[i]<<endl;
    }

    cout <<"Chu thuong: "<<endl;

    for(int i = 0; i < 8; i++)
    {
        cout <<(char)tolower(t[i]);
    }

    cout <<endl<<"Chu hoa: "<<endl;

    for(int i = 0; i < 8; i++)
    {
        cout <<(char)toupper(t[i]);
    }
    cout <<endl;

    cout <<"Do dai cua chuoi la: "<<strlen(t)<<endl;
*/
    // Bài 12: Hãy nhập một xâu kí tự. In ra màn hình đảo ngược của xâu đó.
    string strChuoi = "";
    cout << "Nhap vao 1 chuoi: ";
    getline(cin, strChuoi);

    cout << "Chuoi la: " << strChuoi << endl;

    cout << "Chuoi nguoc la: " << endl;
    for (int i = strChuoi.length(); i >= 0; i--)
    {
        cout << strChuoi[i];
    }

    cout << endl;

    // Bài 13: Nhập xâu. Thống kê số các chữ số ‘0’, số chữ số ‘1’, …, số chữ số ‘9’ trong xâu.
    int tk[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    /*
    //Duyệt từng kí tự để thống kê
    for(int i = 0; i < strChuoi.length(); i++)
    {
        switch (strChuoi[i])
        {
        case '0':
            tk[0]++;
            break;
        case '1':
            tk[1]++;
            break;
        case '2':
            tk[2]++;
            break;
        case '3':
            tk[3]++;
            break;
        case '4':
            tk[4]++;
            break;
        case '5':
            tk[5]++;
            break;
        case '6':
            tk[6]++;
            break;
        case '7':
            tk[7]++;
            break;
        case '8':
            tk[8]++;
            break;
        case '9':
            tk[9]++;
            break;
        }
    }
    */

    // Bài 13 - Cách 2
    // Duyệt từng kí tự để thống kê
    for (int i = 0; i < strChuoi.length(); i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            int giaTri = strChuoi[i] - 48;

            if (j == giaTri)
            {
                tk[j]++;
            }
        }
    }

    cout << "Thong ke so luong tung ki tu la: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << ": " << tk[i] << endl;
    }
    // Bài 14: Nhập xâu. In ra tất các các vị trí của chữ ‘a’ trong xâu và tổng số lần xuất hiện của nó.

    int soLan = 0;

    cout << "Cac vi tri ki tu a xuat hien la: " << endl;

    // Duyệt để thống kê các vị trí kí tự a
    for (int i = 0; i < strChuoi.length(); i++)
    {
        if (strChuoi[i] == 'a')
        {
            cout << i + 1 << endl;
            soLan++;
        }
    }

    cout << "Tong so lan ki tu a xuat hien: " << soLan << endl;
    return 0;
}
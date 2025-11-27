#include <iostream>
//Khai báo thư viện để sử dụng hàm số học
#include <math.h>
#include<iomanip>
using namespace std;

int main()
{
    /*
    //Ví dụ 3: Giải phương trình bậc nhất ax + b = c với a khác 0
    //Khai báo biến
    float a = 0, b = 0, c = 0, x = 0;

    cout <<"Nhap he so a = ";
    cin>>a;

    if(a != 0)
    {
        cout <<"Nhap he so b = ";
        cin>>b;

        cout <<"Nhap he so c = ";
        cin>>c;

        //Giải nghiệm
        x = (c - b)/a;

        cout <<"Nghiem cua phuong trinh bac nhat la: x = "<<x<<endl;
    }
    else
    {
        cout <<"Ban can phai nhap he so a khac 0"<<endl;
    }
*/
    //Thiết lập lấy 2 só sau dấu phẩy
    cout <<setiosflags(ios::fixed)<<setprecision(2);
    //Bài tập 8: Viết chương trình tính và in ra giá trị các biểu thức sau với 2 số lẻ:
    //Khai báo biến
    float cau8a = 0, cau8b = 0;

    //Tính toán
    cau8a = sqrt(3.0 + sqrt(3.0 + sqrt(3.0)));
    cau8b = 1/(2.0 + 1/(2.0 + 1/2.0));

    //pow(2, 3) = 8

    cout <<"Ket qua cau 8a = "<<cau8a<<endl;
    cout <<"Ket qua cau 8b = "<<cau8b<<endl;

    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    //Sử dụng cấp phát động với biến
    int* pr = new int;

    //Gán giá trị
    *pr = 8;

    cout <<"Gia tri cua pr la: "<<*pr<<endl;

    //Xóa vùng nhớ cấp phát
    delete pr;

    //cout <<"Sau khi xoa vung nho. Gia tri cua pr la: "<<*pr<<endl;

    //Sử dụng cấp phát động với mảng
    int* p2 = new int[2];

    //Gán giá trị cho các phần tử
    p2[0] = 2;
    p2[1] = 5;

    cout <<"Gia tri cua phan tu 1 la: "<<p2[0]<<endl;

    cout <<"Cac phan tu cua mang la: "<<endl;

    for(int i = 0; i < 2; i++)
    {
        cout <<p2[i]<<endl;
    }

    //Khai báo 1 mảng số thực gồm n phần tử với n nhập từ bàn phím
    int n = 0;
    cout <<"Nhap mang gom n phan tu n = ";
    cin>>n;

    //Khai báo 1 mảng động
    float* p3 = new float[n];

    cout <<"Nhap gia tri cua cac phan tu: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout <<"p3["<<i<<"] = ";
        cin>>p3[i];
    }

    cout <<"Cac phan tu cua mang gom "<<n<<" phan tu la: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout <<p3[i]<<"\t";
    }
    cout <<endl;
}
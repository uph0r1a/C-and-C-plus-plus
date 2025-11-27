#include <iostream>
using namespace std;

int main()
{
    //Ví dụ 1: Khai báo 1 mảng 2 chiều kiểu số nguyên gồm 3 dòng và 2 cột
    /*
    a00     a01
    a10     a11
    a20     a21
    */
   //Khai báo 1 biến mảng 2 chiều
   int arr[3][2];

   //Gán dữ liệu cho dòng 1
   arr[0][0] = 2;
   arr[0][1] = 3;

   //Dòng 2
   arr[1][0] = 5;
   arr[1][1] = 6;

   //Dòng 3
   arr[2][0] = 8;
   arr[2][1] = 9;

   cout <<"Gia tri cua dong 1 cot 1 la: "<<arr[0][0]<<endl;
   cout <<"Gia tri cua dong 2 cot 1 la: "<<arr[1][0]<<endl;
   cout <<"Gia tri cua dong 3 cot 2 la: "<<arr[2][1]<<endl;

   cout <<"In cac phan tu cua mang 3x2 la: "<<endl;

   //Duyệt dòng
   for(int i = 0; i < 3; i++)
   {
        //Duyệt cột
        for(int j = 0; j < 2; j++)
        {
            cout <<arr[i][j]<<"\t";
        }

        //Xuống dòng
        cout <<endl;
   }
   //Ví dụ 2: Khai báo 1 mảng 2 chiều kiểu số thực gồm m dòng và nột sau đó nhập thông tin cho các phần tử rồi in ra màn hình
   const int MAX = 20;

   //Khai báo biến
   float arr2[MAX][MAX];

   int m = 0, n = 0;
NhapLai:
   cout <<"Nhap mang 2 chieu gom: "<<endl;
   cout <<"Nhap so dong m = ";
   cin>>m;

   cout <<"Nhap so cot n = ";
   cin>>n;

   if(m > MAX || n > MAX)
   {
     cout <<"Ban phai nhap m, n nho hon "<<MAX<<endl;
     goto NhapLai;
   }

   cout <<"Nhap gia tri cho cac phan tu: "<<endl;
   for(int i = 0; i < m; i++)
   {
        for(int j = 0; j < n; j++)
        {
            cout <<"arr2["<<i<<"]["<<j<<"] = ";
            cin >>arr2[i][j];
        }
   }

    cout <<"Cac phan tu cua mang "<<m<<"x"<<n<<" la: "<<endl;
     //Duyệt dòng
   for(int i = 0; i < m; i++)
   {
        //Duyệt cột
        for(int j = 0; j < n; j++)
        {
            cout <<arr2[i][j]<<"\t";
        }

        //Xuống dòng
        cout <<endl;
   }
    return 0;
}
#include <iostream>
#include <vector>
#include<string>
#include <math.h>
using namespace std;

int main()
{
    /*
    //Bài tập 5: Hãy nhập vào 16 số nguyên. In ra thành 4 dòng, 4 cột. Nhập dạng chuỗi
    //Khai báo mảng 2 chiều kiểu số nguyên
    int arr[4][4];

    cout <<"Nhap cac phan tu cho mang: "<<endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout <<"arr["<<i<<"]["<<j<<"] = ";
            cin>>arr[i][j];
        }
    }

    cout <<"Cac phan tu cua mang 4x4 la: "<<endl;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout <<arr[i][j]<<"\t";
        }
        //Xuống dòng
        cout <<endl;
    }

    //Bài tập 8:
    //Nhập ma trận 4x4, báo ra:
    //Số các phần tử lớn hơn 0, liệt kê các phần tử lớn hơn 0 đó, tính tổng của chúng.
    //Số các phần tử nhỏ hơn 0, liệt kê các phần tử nhỏ hơn 0 đó, tính tổng của chúng.

    vector<int> vecDuong, vecAm;
    int tongDuong = 0, tongAm = 0;

    //Xử lý tách mảng 2 chiều về 1 chiều
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(arr[i][j] >= 0)
            {
                vecDuong.push_back(arr[i][j]);
                tongDuong += arr[i][j];
            }
            else
            {
                vecAm.push_back(arr[i][j]);
                tongAm += arr[i][j];
            }
        }
    }

    cout <<"Cac phan tu duong la: "<<endl;
    for(const &i : vecDuong)
    {
        cout <<i<<"\t";
    }
    cout <<endl;
    cout <<"Tong cac phan tu duong la: "<<tongDuong<<endl;

    cout <<"Cac phan tu am la: "<<endl;
    for(const &i : vecAm)
    {
        cout <<i<<"\t";
    }
    cout <<endl;
    cout <<"Tong cac phan tu am la: "<<tongAm<<endl;

    //Bài tập 6:
    //Cho một chuỗi ký tự như sau: “Cong ty Stanford – Dao tao va phat trien cong nghe”. Hãy
    //chuyển chuỗi này thành một mảng, trong đó mỗi phần tử là một từ. Ví dụ a[0] = Cong,a[1] = ty, a[2] = Stanford,…Sau đó in kết quả ra màn hình
    
    string strCongTy = "Cong ty Stanford - Dao tao va phat trien cong nghe";

    vector<string> words;

    //Duyệt từng kí tự trong chuỗi
    string temp = "";
    for(int i = 0; i <= strCongTy.length();i++)
    {
        //Khi gặp kí tự khoảng trắng hoặc cuối chuỗi thì gán chuỗi temp vào danh sách
        if (strCongTy[i] == ' ' || i == strCongTy.length())
        {
            words.push_back(temp);
            temp = "";
        }
        else
        {
            temp += strCongTy[i];
        }
    }

    cout <<"Cac tu sau khi cat ra la: "<<endl;
    for(const string &gt : words)
    {
        cout <<gt<<endl;
    }
*/
    //Bài 11: Viết chương trình nhập vào N số nguyên(N nhỏ hơn 20) và tính tổng các số nguyên tố trong các số đã nhập vào đó.
    const int MAX = 20;

    int arr[MAX];

    int n = 0;
NhapLai:
    cout <<"Nhap mang gom n phan tu voi n = ";
    cin>>n;

    if(n > MAX){
        cout <<"Ban can phai nhap n nho hon "<<MAX<<endl;
        goto NhapLai;
    }

    cout <<"Nhap cac phan tu: "<<endl;

    for(int i = 0; i < n; i++)
    {
        cout <<"arr["<<i<<"] = ";
        cin>>arr[i];
    }

    cout <<"Cac so nguyen to la: "<<endl;

    //Duyệt để tìm số nguyên tố và tính tổng
    bool isSoNguyenTo = true;
    int tongSoNguyenTo = 0;
    for(int i = 0; i < n; i++)
    {
        int giaTri = (int)sqrt(arr[i]);
        isSoNguyenTo = true;
        //Kiểm tra xem có phải là số nguyên tố không
        for(int j = 2; j <= giaTri; j++)
        {
            if(arr[i]%j == 0)
            {
                isSoNguyenTo = false;
            }
        }
        if(isSoNguyenTo)
        {
                 tongSoNguyenTo += arr[i];   
                 cout <<arr[i]<<endl;
        }
    }

    cout <<"Tong cac so nguyen to la: "<<tongSoNguyenTo<<endl;


    return 0;
}
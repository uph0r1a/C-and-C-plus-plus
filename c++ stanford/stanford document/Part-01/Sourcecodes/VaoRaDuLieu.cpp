#include<stdio.h>
#include<conio.h>
#include<iostream>
//Khai báo lấy bao nhiêu số lẻ sau dấu phẩy
#include<iomanip>
using namespace std;

int main()
{
    /*
    //Khai báo biến tuổi của sinh viên
    int tuoiSV = 20;

    cout <<"Tuoi sinh vien la: "<<tuoiSV<<endl;

    //Gán giá trị mới
    tuoiSV = 21;

    cout <<"Tuoi sinh vien moi la: "<<tuoiSV<<endl;

    cout <<"Nhap tuoi sinh vien = "; 

    //Nhập tuổi
    cin>>tuoiSV;

    cout <<"Tuoi moi sinh vien nhap la: "<<tuoiSV<<endl;

    //In thông tin sử dụng C
    printf("Chao mung cac ban den voi lap trinh C\n");

    //Khai báo biến
    int soCay = 0;

    printf("Nhap so luong cay = ");

    scanf("%d", &soCay);

    printf("So luong cay nhap la: %d\n", soCay);


    cout <<"Xin chao cac ban !"<<endl;
    cout <<"Chuc cac ban hoc tap tot !"<<endl;

    //Xóa thông tin trên màn hình trước đó
    system("cls");

    //clrscr();
    //Khai báo kí tự
    int soNha = 0;
    char kiTu;

    cout <<"Nhap so nha = ";
    cin>>soNha;

    //Xóa kí tự thừa
    cin.ignore(1);

    cout <<"Nhap ki tu la = ";
    cin.get(kiTu);

    cout <<"So nha la: "<<soNha<<endl;
    cout <<"Ki tu la: "<<kiTu<<endl;

    cout <<"Kich thuoc kieu char la: "<<sizeof(char)<<" byte"<<endl;
    cout <<"Kich thuoc kieu short la: "<<sizeof(short)<<" byte"<<endl;
    cout <<"Kich thuoc kieu int la: "<<sizeof(int)<<" byte"<<endl;
    cout <<"Kich thuoc kieu uint la: "<<sizeof(unsigned int)<<" byte"<<endl;
    */
    //Thiết lập lấy 2 só sau dấu phẩy
    cout <<setiosflags(ios::fixed)<<setprecision(2);

    /*
    //Khai báo biến số lẻ
    //float diemTrungBinh = 8.6835;
    //cout <<"Diem trung binh la: "<<diemTrungBinh<<endl;

    //Bài tập 1: Viết câu lệnh khai báo biến để lưu các giá trị sau:
    //− Tuổi của một người − Số lượng cây trong thành phố
    unsigned short tuoiNguoi = 20;
    unsigned int soLuongCay = 10000;
    //− Độ dài cạnh một tam giác − Khoảng cách giữa các hành tinh
    float canhTamGiac = 24.5665;
    double khoangCach = 5464646546.5675;
    //− Một chữ số − Nghiệm x của phương trình bậc 1
    char chuSo = '9';
    float x = 12.3454;
    //− Một chữ cái − Biệt thức Δ của phương trình bậc 2
    char chuCai = 'A';
    float delta = 25.56765;

    cout <<"Tuoi nguoi la: "<<tuoiNguoi<<endl;
    cout <<"So luong cay la: "<<soLuongCay<<endl;
    cout <<"Canh tam giac la: "<<canhTamGiac<<endl;
    cout <<"Khoang cach giua cac hanh tinh: "<<khoangCach<<endl;
    cout <<"Chu so la: "<<chuSo<<endl<<"Chu cai la: "<<chuCai<<endl;
    cout <<"Nghiem cua x = "<<x<<endl;
    cout <<"Biet thuc delta = "<<delta<<endl;

    //Bài tập 2: Viết câu lệnh nhập vào 4 giá trị lần lượt là số thực, nguyên, nguyên dài và kí
    //tự. In ra màn hình các giá trị này để kiểm tra.
    //Khai báo biến
    float soThuc = 0;
    int soNguyen = 0;
    long soNguyenDai = 0;
    char kiTu;

    cout <<"Nhap 1 so thuc la: ";
    cin>>soThuc;

    cout <<"Nhap 1 so nguyen la: ";
    cin>>soNguyen;

    cout <<"Nhap 1 so nguyen dai la: ";
    cin>>soNguyenDai;

    cout <<"Nhap ki tu la: ";
    //Xóa kí tự thừa xuống dòng
    cin.ignore(1);

    //Nhập kí tự
    cin.get(kiTu);

    //In thông tin ra màn hình
    cout <<"So thuc la: "<<soThuc<<endl;
    cout <<"So nguyen: "<<soNguyen<<endl<<"So nguyen dai: "<<soNguyenDai<<endl;
    cout <<"Ki tu la: "<<kiTu<<endl;

    //Bài tập 4: Viết chương trình nhập vào một kí tự. In ra kí tự đó và mã ascii của nó.
    cout <<"Ki tu "<<kiTu<<" co ma ascii la: "<<(int)kiTu<<endl;

    
    //Ví dụ 1: Nhập vào 2 số thực a và b sau đó tính tổng, hiệu, tích, thương của 2 số đó 
    //Khai báo biến
    float a = 0, b = 0, tong = 0, hieu = 0, tich = 0, thuong = 0;

    //Nhập thông tin từ bàn phím
    cout <<"Nhap gia tri a = ";
    cin>>a;
    cout <<"Nhap gia tri b = ";
    cin>>b;

    //Tính toán
    tong = a + b;
    hieu = a - b;
    tich = a * b;
    thuong = a/b;

    //In kết quả
    cout <<"Tong hai so "<<a<<" va "<<b<<" la: "<<tong<<endl;
    cout <<"Hieu hai so "<<a<<" va "<<b<<" la: "<<hieu<<endl;
    cout <<"Tich hai so "<<a<<" va "<<b<<" la: "<<tich<<endl;
    cout <<"Thuong hai so "<<a<<" va "<<b<<" la: "<<thuong<<endl;
*/

    //Ví dụ 2: Nhập chiều cao của Dũng và Trí sau đó kiểm tra xem ai cao hơn rồi in ra màn hình
    //Khai báo biến
    float chieuCaoDung = 0, chieuCaoTri = 0;

    cout <<"Nhap chieu cao cua Dung = ";
    cin>>chieuCaoDung;

    cout <<"Nhap chieu cao cua Tri = ";
    cin>>chieuCaoTri;

    if(chieuCaoDung == chieuCaoTri)//true
    {
        cout <<"Chieu cao cua Dung va Tri bang nhau"<<endl;
    }
    else
    {
        if(chieuCaoDung > chieuCaoTri)//true
        {
            cout <<"Chieu cao cua Dung cao hon Tri"<<endl;
        }
        else
        {
            cout <<"Chieu cao cua Dung thap hon Tri"<<endl;
        }
    }

    return 0;
}
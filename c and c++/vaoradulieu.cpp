#include <stdio.h>
#include <iostream>
#include <conio.h>
// khai báo lấy bao nhiêu số lẻ sau dấu phẩy
#include <iomanip>

using namespace std;

int main()
{
     int tuoiSV = 20;
     cout << "Tuoi sinh vien la " << tuoiSV << endl;

     tuoi = 21;
     cout << "tuoi sinh vien moi la " << tuoiSV << endl;

     cin >> tuoiSV;

     cout << "tuoi moi sinh vien nhap lai" << tuoiSV << endl;
     int soCay = 0;

     printf("Nhap so luong cay = ");

     scanf("%d", &soCay);

     printf("So luong cay nhap la: %d\n", soCay);

     cout << "xin chao cac ban" << endl;
     cout << "chuc cac ban hoc tot" << endl;

     system("cls");

     // clrscr();
     // Khai báo kí tự
     int soNha = 0;
     char kiTu;

     cout << "Nhap so nha = ";
     cin >> soNha;

     // Xóa kí tự thừa
     cin.ignore(1);

     cout << "Nhap ki tu la = ";

     cin.get(kiTu);

     cout << "So nha la: " << soNha << endl;
     cout << "Ki tu la: " << kiTu << endl;

     cout << "kich thuoc kieu int la: " << sizeof(int) << " byte" << endl;
     cout << "kich thuoc kieu int la: " << sizeof(char) << " byte" << endl;
     cout << "kich thuoc kieu int la: " << sizeof(short) << " byte" << endl;
     cout << "kich thuoc kieu int la: " << sizeof(unsigned int) << " byte" << endl;

     // thiết lập lấy 2 số sau dấu phẩy
     cout << setiosflags(ios::fixed) << setprecision(2);
     // khai báo biến số lẻ
     float diemTrungBinh = 8.6635;
     cout << "Diem trung binh la: " << diemTrungBinh << endl;

     // bt1: viết câu lệnh khai báo biến để lưu các giá trị sau
     //-tuổi của 1 người - số lượng cây trong thành phố
     unsigned short tuoiNguoi = 20;
     unsigned int soluongCay = 100000;
     //-độ dài cạnh 1 tam giác - khoảng cách giữa các hành tinh
     float cachTamGiac = 24.5665;
     double khoangCach = 546464546.5675;
     //-1 chữ số - ngiệm x của phương trình bậc 1
     char chuso = '9';
     float x = 12.3454;
     //-1 chữ cái - biệt thức delta của phương trình bậc 2
     char chuCai = 'A';
     float delta = 25.56765;

     cout << "Tuoi nguoi la: " << tuoiNguoi << endl;
     cout << "So luong cay la: " << soluongCay << endl;
     cout << "Canh tam giac la: " << cachTamGiac << endl;
     cout << "Khoang cach giua cac hanh tinh: " << khoangCach << endl;
     cout << "Chu so la: " << chuso << endl
          << "chu cai la: " << chuCai << endl;
     cout << "Nghiem cua x = " << x << endl;
     cout << "biet thuc delta = " << delta << endl;

     // bt2: Viết câu lệnh nhập vào 4 giá trị lần lượt là số thục, nguyên, nguyên dài, kí tự. In ra màn hình các giá trị này để kiểm tra.
     // Khai báo biến
     float soThuc = 0;
     int soNguyen = 0;
     long soNguyenDai = 0;
     char kiTu;
     cout << "Nhap 1 so thuc la: ";
     cin >> soThuc;
     cout << "Nhap 1 so nguyen la: ";
     cin >> soNguyen;
     cout << "Nhap 1 so nguyen dai la: ";
     cin >> soNguyenDai;
     cout << "Nhap ki tu la: ";
     // Xóa kí tự thừa xuống dòng
     cin.ignore(1);
     // Nhập kí tự
     cin.get(kiTu);
     // In thông tin ra màn hình
     cout << "So thuc la: " << soThuc << endl;
     cout << "So nguyen: " << soNguyen << endl
          << "So nguyen dai: " << soNguyenDai << endl;
     cout << "Ki tu la: " << kiTu << endl;

     return 0;
}
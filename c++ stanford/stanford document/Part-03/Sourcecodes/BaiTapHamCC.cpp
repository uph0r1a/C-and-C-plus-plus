#include<iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

//Tìm ước số chung sử dụng giải thuật Euclid
int TimUocSoChungLonNhat(int a, int b)
{

    int t = 0;

    while(b != 0)
    {
        t = b;
        b = b%a;
        a = t;
    }

    return a;
}
//Tìm ước số chung lớn nhất
int TimUocSoChungLonNhat2(int a, int b)
{
    int min = a < b ? a: b, uocChungLonNhat = 0;

    //Duyệt vòng lặp
    for(int i = min; i>=1; i--)
    {
        if(a%i == 0 && b%i == 0)
        {
            uocChungLonNhat = i;
            break;
        }
    }

    return uocChungLonNhat;
}

//Hàm kiểm tra năm nhuận
bool KiemTraNamNhuan(int nam)
{
    if((nam%4 == 0 && nam%100 != 0) || (nam%100 == 0 && nam%400 == 0))
    {
        return true;
    }

    return false;
}

void TimNamNhuanTheoKhoang(int tuNam, int denNam)
{
    cout <<"Cac nam nhuan tu nam "<<tuNam<<" den nam "<<denNam<<":"<<endl;

    for(int i = tuNam; i<= denNam; i++)
    {
        if(KiemTraNamNhuan(i))
        {
            cout <<i<<endl;
        }
    }
}

void GiaiPhuongTrinhBacHai()
{
    //Khai báo biến
    double a = 0, b = 0, c = 0, delta = 0, x1 = 0, x2 = 0;

    cout <<"Nhap he so a = ";
    cin>>a;
    if(a != 0){
        cout <<"Nhap he so b = ";
        cin>>b;
        cout <<"Nhap he so c = ";
        cin>>c;

        //Tính delta
        delta = pow(b, 2) - 4*a*c;

        if(delta < 0)
        {
            cout <<"Phuong trinh vo nghiem"<<endl;
        }
        else
        {
            if(delta == 0)
            {
                x1 = -b/(2*a);
                cout <<"Phuong trinh co nghiem  kep x1 = x2 = "<<x1<<endl;
            }
            else
            {
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);

                cout <<"Phuong trinh co 2 nghiem phan biet, x1 = "<<x1<<", x2 = "<<x2<<endl;
            }
        }
    }
    else
    {
        cout <<"Ban phai nhap he so a khac 0";
    }
}

double DienTichHinhTron(double banKinh)
{
    const double PI = 3.14;

    return PI*banKinh*banKinh;
}

double DienTichHinhVuong(double a)
{
    return a*a;
}

double DienTichGioiHanHinhVuongNgoaiTiepHinhTron(double r)
{
    double dienTichHT = 0, dienTichHV = 0, dienTichGH = 0;

    dienTichHT = DienTichHinhTron(r);
    dienTichHV  = DienTichHinhVuong(2*r);

    dienTichGH = dienTichHV - dienTichHT;

    return dienTichGH;
}

string ChuyenSangSoNhiPhan(int soThapPhan)
{
    string  strSoNhiPhan = "";

    string arr[20];

    int soDu = 0, soLuong = 0;
    while(soThapPhan > 0)
    {
        soDu = soThapPhan%2;
        soThapPhan = soThapPhan/2;

        //Chuyển số về chuỗi
        stringstream convert;

        convert<<soDu;

        arr[soLuong] = convert.str();
        soLuong++;
    }

    //Duyệt ngược
    for(int i = soLuong-1; i>= 0; i--)
    {
        strSoNhiPhan += arr[i];
    }

    return strSoNhiPhan;
}

int ChuyenSangSoThapPhan(string soNhiPhan)
{
    int soThapPhan = 0;

    for(int i = 0; i < soNhiPhan.length(); i++)
    {
        if(soNhiPhan[i] == '1')
        {
            soThapPhan += (int)pow(2, soNhiPhan.length() - i - 1);
        }
    }

    return soThapPhan;
}

int main()
{
    /*
    //Bài tập 4: Viết hàm tìm UCLN của 2 số. áp dụng hàm này để tìm UCLN của 4 số nhập
    //từ bàn phím.

    //Khai báo biến
    int a = 0, b = 0, uocChungLN = 0;

    cout <<"Nhap so thu 1 = ";
    cin>>a;
    cout <<"Nhap so thu 2 = ";
    cin>>b;

    //Gọi hàm để tìm ước chung lớn nhất
    uocChungLN = TimUocSoChungLonNhat2(a, b);

    cout <<"Uoc so chung lon nhat cua "<<a<<" va "<<b<<" la: "<<uocChungLN<<endl;

    //Bài tập 5: Viết hàm kiểm tra một năm có là năm nhuận. In ra các năm nhuận từ năm 1000 đến 2000.
    int tuNam = 0, denNam = 0;

    cout <<"Nhap tu nam can tinh nam nhuan = ";
    cin>>tuNam;

    cout <<"Den nam = ";
    cin>>denNam;

    //Gọi hàm
    TimNamNhuanTheoKhoang(tuNam, denNam);

    //Bài tập 7:
    //Viết hàm giải phương trình bậc 2. Sau đó thực hiện tính toán trên giao diện cho phép người dùng nhập thông tin sau khi thực hiện tính toán sẽ hiển thị kết quả deltal và nghiệm của phương trình.
    //GiaiPhuongTrinhBacHai();

    //Bài tập 8:
    //Tính phần diện tích giới hạn bởi hình tròn bán kính R và hình vuông ngoại tiếp của nó.

    //Khai báo biến
    double r = 0, dienTichGT = 0;

    cout <<"Nhap vao ban kinh hinh tron r = ";
    cin>>r;

    //Gọi hàm tính toán
    dienTichGT = DienTichGioiHanHinhVuongNgoaiTiepHinhTron(r);

    cout <<"Dien tich gioi han cua hinh vuong ngoai tiep hinh tron la: "<<dienTichGT<<endl;*/

    //Bài tập 9:
    //Viết một hàm chuyển dữ liệu số thập phân sang số nhị phân

    int n = 0;
    string soNhiPhan = "";

    cout <<"Nhap gia tri can chuyen ve so nhi phan n = ";
    cin>>n;

    //Gọi hàm chuyển đổi
    soNhiPhan = ChuyenSangSoNhiPhan(n);

    cout <<"So nhi phan la: "<<soNhiPhan<<endl;

    //Bài tập 13:
    //Viết một hàm chuyển dữ liệu từ nhị phân sang thập phân
    //Xóa kí tự thừa
    cin.ignore(1);
    cout <<"Nhap so nhi phan can chuyen = ";
    getline(cin, soNhiPhan);

    //Gọi hàm chuyển đổi
    int soThapPhan = 0;

    soThapPhan = ChuyenSangSoThapPhan(soNhiPhan);

    cout <<"So thap phan la: "<<soThapPhan<<endl;

}
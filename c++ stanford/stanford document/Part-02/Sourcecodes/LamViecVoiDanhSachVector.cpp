#include <iostream>
#include <vector>
//Khai báo thư viện để làm việc với chuỗi
#include <string>
using namespace std;

int main()
{
    //Khai báo 1 danh sách
    vector<int> arr = {1, 2, 3};

    cout <<"Gia tri cua phan tu 1 la: "<<arr[0]<<endl;
    cout <<"Gia tri cua phan tu 2 la: "<<arr[1]<<endl;

    //Thêm 1 phần tử
    arr.push_back(5);

    //Chèn giá trị vào vị trí đầu tiên
    arr.insert(arr.begin(), 8);

    cout <<"Cac phan tu trong danh sach: "<<endl;
    //Duyệt từng phần tử để in ra
    for(const int &i : arr)
    {
        cout <<i<<"\t";
    }

    cout <<endl;

    cout <<"Phan tu dau tien: "<<arr.front()<<endl;
    cout <<"Phan tu cuoi cung: "<<arr.back()<<endl;

    cout <<"Phan tu o vi tri thu 3: "<<arr.at(2)<<endl;

    cout <<"So luong phan tu cua danh sach la: "<<arr.size()<<endl;

    //Xóa phần tử
    arr.erase(arr.end());

    cout <<"In danh sach cac phan tu trong danh sach: "<<endl;

    for(auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout <<*i<<endl;
    }

    //Khai báo biến
    string strChuoi = "";

    cout <<"Nhap vao 1 chuoi la: "<<endl;

    //Lấy 1 chuỗi và gán cho biến
    getline(cin, strChuoi);

    cout<<"Chuoi thong tin la: "<<strChuoi<<endl;
    
    return 0;
}
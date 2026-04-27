#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3};

    arr.push_back(5);
    arr.insert(arr.begin(), 8);

    cout << "Cac phan tu: ";
    for (int v : arr)
        cout << v << " ";
    cout << "\n";

    cout << "Phan tu dau: " << arr.front() << "\n";
    cout << "Phan tu cuoi: " << arr.back() << "\n";
    cout << "Vi tri thu 3: " << arr.at(2) << "\n";
    cout << "So phan tu: " << arr.size() << "\n";

    arr.pop_back();

    cout << "Sau khi xoa phan tu cuoi: ";
    for (int v : arr)
        cout << v << "  ";
    cout << "\n";

    string str;
    cout << "Nhap vao 1 chuoi: ";
    getline(cin, str);
    cout << "Chuoi nhap: " << str << "\n";
    cout << "Do dai: " << str.length() << "\n";

    return 0;
}

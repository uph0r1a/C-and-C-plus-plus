#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    const string ngay[] = {
        "", "Thu 2", "Thu 3", "Thu 4",
        "Thu 5", "Thu 6", "Thu 7", "Chu Nhat"};

    int n;
    cout << "Nhap so (1-7): ";
    cin >> n;

    if (n >= 1 && n <= 7)
        cout << ngay[n] << "\n";
    else
        cout << "Khong phai thu trong tuan.\n";

    return 0;
}

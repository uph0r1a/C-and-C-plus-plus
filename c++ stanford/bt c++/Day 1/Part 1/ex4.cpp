#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char kyTu;
    cout << "Nhap mot ky tu: ";
    cin >> kyTu;
    cout << "Ky tu: " << kyTu << "\n";
    cout << "Ma ASCII: " << static_cast<int>(kyTu) << "\n";
    return 0;
}

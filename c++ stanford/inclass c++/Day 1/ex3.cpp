#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char kiTu;

    cout << "Nhap mot ki tu: ";
    cin.get(kiTu);

    cout << "Ki tu: " << kiTu << endl;
    cout << "Ma ASCII: " << (int)kiTu << endl;

    return 0;
}

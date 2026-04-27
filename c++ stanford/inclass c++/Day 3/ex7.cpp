#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 20;
    int *p = &x;

    cout << "Gia tri x = " << x << "\n";
    cout << "Dia chi &x = " << &x << "\n";
    cout << "p (dia chi luu) = " << p << "\n";
    cout << "*p (gia tri) = " << *p << "\n\n";

    const int MAX = 3;
    int arr[MAX] = {100, 200, 300};
    int *p2 = arr;

    cout << "Truoc p2++: dia chi = " << p2 << ", gia tri = " << *p2 << "\n";
    p2++;
    cout << "Sau  p2++: dia chi = " << p2 << ", gia tri = " << *p2 << "\n";
    p2--;

    cout << "Duyet mang qua con tro:\n";
    for (int i = 0; i < MAX; i++, p2++)
        cout << "dia chi: " << p2 << "  gia tri: " << *p2 << "\n";

    string tenCongTy = "Stanford - Day lap trinh";
    string *p3 = &tenCongTy;

    cout << "p3 = " << p3 << "\n";
    cout << "*p3= " << *p3 << "\n";

    char s[10];
    strcpy(s, "Stanford");
    char *p4 = s;

    for (int i = 0; i < 8; i++, p4++)
        cout << "dia chi: " << (void *)p4 << "  gia tri: " << *p4 << "\n";

    int *p5[MAX];
    for (int i = 0; i < MAX; i++)
        p5[i] = &arr[i];

    for (int i = 0; i < MAX; i++)
        cout << "p5[" << i << "]: dia chi = " << p5[i] << "  gia tri = " << *p5[i] << "\n";

    int &r = x;
    cout << "Truoc r++: x = " << x << "\n";
    r++;
    cout << "Sau r++: x = " << x << " (r va x cung 1 o nho)\n";

    return 0;
}

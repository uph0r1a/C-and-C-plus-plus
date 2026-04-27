#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char ch;
    char *pc = &ch;

    cout << "Nhap mot ky tu: ";
    cin.get(ch);
    cout << "Ky tu vua nhap: " << ch << endl;
    cout << endl;

    ch = 'A';
    cout << "Cach 1 - Gan truc tiep (ch = 'A'): " << ch << endl;

    *pc = 'A';
    cout << "Cach 2 - Gan qua con tro (*pc = 'A'): " << ch << endl;

    pc[0] = 'A';
    cout << "Cach 3 - Gan qua chi so mang (pc[0] = 'A'): " << ch << endl;

    cout << endl;
    cout << "Dia chi cua ch: " << (void *)&ch << endl;
    cout << "Gia tri con tro pc luu (dia chi): " << (void *)pc << endl;
    cout << "Gia tri lay qua con tro (*pc): " << *pc << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int cha, con;

    while (1)
    {
        cout << "Nhap tuoi cha (> 0): ";
        cin >> cha;
        cout << "Nhap tuoi con (> 0): ";
        cin >> con;
        if (cha > 0 && con > 0 && cha > 2 * con)
            break;
        cout << "[!] Can: cha > 2 x con va ca hai > 0. Nhap lai.\n\n";
    }

    int n = cha - 2 * con;

    cout << "Sau " << n << " nam nua:\n";
    cout << "Tuoi cha = " << cha + n << ", tuoi con = " << con + n << "\n";
    cout << cha + n << " = 2 x " << con + n << " (dung)\n";

    return 0;
}

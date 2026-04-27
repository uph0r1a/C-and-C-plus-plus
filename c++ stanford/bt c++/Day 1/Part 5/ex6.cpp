#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    const string CORRECT_USER = "user123";
    const string CORRECT_PASS = "pass456";
    const int MAX_ATTEMPTS = 3;

    string user, pass;
    int attempt = 0;

    while (attempt < MAX_ATTEMPTS)
    {
        attempt++;
        cout << "Lan " << attempt << "/" << MAX_ATTEMPTS << "\n";
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == CORRECT_USER && pass == CORRECT_PASS)
        {
            cout << "Dang nhap thanh cong! Chao mung " << user << ".\n";
            return 0;
        }

        int remaining = MAX_ATTEMPTS - attempt;
        if (remaining > 0)
            cout << "Sai thong tin. Con " << remaining << " lan thu.\n\n";
    }

    cout << "Tai khoan bi khoa sau " << MAX_ATTEMPTS << " lan thu that bai.\n";
    return 1;
}

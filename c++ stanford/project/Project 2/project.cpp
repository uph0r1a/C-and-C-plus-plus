#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
using namespace std;

static const string USERNAME = "username";
static const string PASSWORD = "password";
static const int MAX_ATTEMPTS = 3;

static string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

static void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool login()
{
    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        string username, password;
        cout << "Nhap username: ";
        cin >> username;
        cout << "Nhap password: ";
        cin >> password;

        if (username == USERNAME && password == PASSWORD)
        {
            cout << "Dang nhap thanh cong!\n";
            return true;
        }

        int remaining = MAX_ATTEMPTS - attempt;
        if (remaining > 0)
            cout << "Sai thong tin. Con " << remaining << " lan thu.\n\n";
    }
    return false;
}

using Dictionary = map<string, string>;

void traCuu(const Dictionary &dict)
{
    string word;
    cout << "Nhap tu can tra: ";
    cin >> word;
    word = toLower(word);

    auto it = dict.find(word);
    if (it != dict.end())
        cout << "'" << word << "' : " << it->second << '\n';
    else
        cout << "Tu '" << word << "' khong co trong tu dien.\n";
}

void themTuMoi(Dictionary &dict)
{
    string word, meaning;
    cout << "Nhap tu moi: ";
    cin >> word;
    word = toLower(word);

    auto it = dict.find(word);
    if (it != dict.end())
    {
        cout << "Tu '" << word << "' da ton tai voi nghia: " << it->second << '\n';
        cout << "Ban co muon cap nhat khong? (c/k): ";
        char confirm;
        cin >> confirm;
        if (confirm != 'c' && confirm != 'C')
        {
            cout << "Huy bo.\n";
            return;
        }
    }

    clearInput();
    cout << "Nhap nghia cua '" << word << "': ";
    getline(cin, meaning);

    dict[word] = meaning;
    cout << "[+] Da luu '" << word << "'.\n";
}

void lietKeTatCa(const Dictionary &dict)
{
    if (dict.empty())
    {
        cout << "Tu dien trong.\n";
        return;
    }
    cout << '\n'
         << string(40, '-') << '\n';
    for (const auto &[word, meaning] : dict)
        cout << "  " << word << " : " << meaning << '\n';
    cout << string(40, '-') << '\n';
    cout << "Tong so tu: " << dict.size() << '\n';
}

int main(int argc, char const *argv[])
{
    Dictionary dict = {
        {"apple", "qua tao"},
        {"computer", "may tinh"},
        {"book", "quyen sach"},
    };

    cout << "=== TU DIEN TIENG ANH ===\n\n";

    if (!login())
    {
        cout << "Dang nhap that bai. Chuong trinh ket thuc.\n";
        return 1;
    }

    int choice;
    do
    {
        cout << "\n--- MENU ---\n"
             << "1. Tra cuu tu\n"
             << "2. Them / cap nhat tu\n"
             << "3. Liet ke tat ca tu\n"
             << "4. Thoat\n"
             << "Chon: ";

        if (!(cin >> choice))
        {
            clearInput();
            choice = -1;
        }

        switch (choice)
        {
        case 1:
            traCuu(dict);
            break;
        case 2:
            themTuMoi(dict);
            break;
        case 3:
            lietKeTatCa(dict);
            break;
        case 4:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 4);

    return 0;
}
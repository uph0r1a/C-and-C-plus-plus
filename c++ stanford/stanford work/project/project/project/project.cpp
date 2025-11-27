#include <iostream>
#include <map>
#include <string>

using namespace std;

const string USERNAME = "username";
const string PASSWORD = "password";

bool login() {
    string username, password;
    cout << "Nhap username: ";
    cin >> username;
    cout << "Nhap password: ";
    cin >> password;

    if (username == USERNAME && password == PASSWORD) {
        return true;
    }
    else {
        return false;
    }
}

void traCuu(map<string, string>& dictionary) {
    string word;
    cout << "Nhap tu can tra: ";
    cin >> word;

    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        cout << "Nghia cua tu '" << word << "' la: " << it->second << endl;
    }
    else {
        cout << "Tu '" << word << "' khong co trong tu dien." << endl;
    }
}

void themTuMoi(map<string, string>& dictionary) {
    string word, meaning;
    cout << "Nhap tu moi: ";
    cin >> word;
    cout << "Nhap nghia cua tu '" << word << "': ";
    cin.ignore();
    getline(cin, meaning);

    dictionary[word] = meaning;
    cout << "Them tu moi thanh cong!" << endl;
}

int main() {
    map<string, string> dictionary;
    int choice;

    dictionary["apple"] = "tao";
    dictionary["computer"] = "may tinh";

    cout << "Chao mung ban den voi tu dien tieng Anh!" << endl;
    if (!login()) {
        cout << "Dang nhap khong thanh cong!" << endl;
        return 0;
    }

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Tra cuu tu\n";
        cout << "2. Them tu moi\n";
        cout << "3. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;

        switch (choice) {
        case 1:
            traCuu(dictionary);
            break;
        case 2:
            themTuMoi(dictionary);
            break;
        case 3:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai." << endl;
            break;
        }
    } while (choice != 3);
}
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    char s[20], t[20];

    strcpy(t, "Stanford");
    strncpy(s, t, 5);
    s[5] = '\0';

    strcat(s, "Ord");

    cout << "s = " << s << "\n";
    cout << "t = " << t << "\n";

    int kq = strcmp(s, t);
    cout << "strcmp(s, t) = " << kq
         << (kq == 0 ? "  (bang nhau)" : (kq < 0 ? "  (s < t)" : "  (s > t)"))
         << "\n";

    kq = strncmp(s, t, 5);
    cout << "strncmp(s, t, 5) = " << kq << "\n";

    cout << "strlen(t) = " << strlen(t) << "\n";

    cout << "t chu thuong: ";
    for (int i = 0; t[i] != '\0'; i++)
        cout << (char)tolower((unsigned char)t[i]);
    cout << "\n";

    cout << "t chu hoa: ";
    for (int i = 0; t[i] != '\0'; i++)
        cout << (char)toupper((unsigned char)t[i]);
    cout << "\n";

    return 0;
}

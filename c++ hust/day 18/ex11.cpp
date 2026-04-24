#include <iostream>
#include <cctype>
using namespace std;

bool isPalindromeRec(const string &s, int left, int right)
{
    if (left >= right)
        return true;

    if (!isalnum(s[left]))
        return isPalindromeRec(s, left + 1, right);

    if (!isalnum(s[right]))
        return isPalindromeRec(s, left, right - 1);

    if (tolower(s[left]) != tolower(s[right]))
        return false;

    return isPalindromeRec(s, left + 1, right - 1);
}

bool isPalindrome(string s)
{
    return isPalindromeRec(s, 0, s.length() - 1);
}

int main(int argc, char const *argv[])
{
    string test1 = "Able was I, ere I saw Elba";
    string test2 = "A man, a plan, a canal, Panama";
    string test3 = "Desserts, I stressed";
    string test4 = "Kayak";
    string test5 = "Hello";

    cout << boolalpha;

    cout << test1 << " -> " << isPalindrome(test1) << endl;
    cout << test2 << " -> " << isPalindrome(test2) << endl;
    cout << test3 << " -> " << isPalindrome(test3) << endl;
    cout << test4 << " -> " << isPalindrome(test4) << endl;
    cout << test5 << " -> " << isPalindrome(test5) << endl;

    return 0;
}
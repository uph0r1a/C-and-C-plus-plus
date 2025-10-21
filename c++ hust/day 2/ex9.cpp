#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int cookies_eaten;
    cout << "How many cookies did you ate: ";
    cin >> cookies_eaten;
    cout << "Total calories were consumed: " << cookies_eaten * 100;
    return 0;
}

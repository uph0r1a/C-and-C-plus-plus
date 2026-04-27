#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
     char c1 = static_cast<char>(200);
     unsigned char c2 = 200;

     cout << "c1 = " << static_cast<int>(c1) << ", c2 = " << static_cast<int>(c2) << "\n";
     cout << "c1+100 = " << c1 + 100 << ", c2+100 = " << c2 + 100 << "\n";

     return 0;
}

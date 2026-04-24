#include <iostream>
using namespace std;

int power(int n, int exp){
    if (exp == 0)
    {
        return 1;
    }

    return n * power(n,exp-1);
}

int main(int argc, char const *argv[])
{
    int n = 2, exp = 2;
    cout<<power(n,exp);
    return 0;
}

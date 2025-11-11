#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float rate = 0.04;
    for (int i = 0; i <= 6; i++)
    {
        cout<<"The projected rates for year "<<i<<" is: $"<<2500 + 2500*rate*i<<"\n";
    }
    
    return 0;
}

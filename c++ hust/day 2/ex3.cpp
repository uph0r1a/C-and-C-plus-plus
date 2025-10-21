#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float scores[5], sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Test scores no " << i + 1 << ": ";
        cin >> scores[i];
        sum += scores[i];
    }
    cout << fixed << setprecision(1) << sum / 5 << endl;
    return 0;
}

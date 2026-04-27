#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<bool> sieve(int limit)
{
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; (long long)i * i <= limit; i++)
        if (is_prime[i])
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
    return is_prime;
}

int digitSum(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    int S;
    do
    {
        cout << "Nhap tong chu so S (1-45): ";
        cin >> S;
    } while (S < 1 || S > 45);

    auto is_prime = sieve(99999);

    int count = 0;
    cout << "\nCac so nguyen to 5 chu so co tong chu so = " << S << ":\n";
    for (int n = 10000; n <= 99999; n++)
    {
        if (is_prime[n] && digitSum(n) == S)
        {
            cout << setw(6) << n;
            if (++count % 10 == 0)
                cout << "\n";
        }
    }
    cout << "\nTong cong: " << count << " so.\n";
    return 0;
}

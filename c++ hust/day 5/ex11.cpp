#include <iostream>
using namespace std;

void getScore(int &test_score)
{
    cout << "Enter the test score: ";
    while (true)
    {
        cin >> test_score;
        if (test_score >= 0 && test_score <= 100)
            break;

        cout << "Score must be between 0 and 100\nRe-enter the test score:  ";
    }
}

int findLowest(int a, int b, int c, int d, int e)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;
    if (e < min)
        min = e;
    return min;
}

void calcAverage(int a, int b, int c, int d, int e)
{
    int lowest = findLowest(a, b, c, d, e);

    int sum = a + b + c + d + e - lowest;
    double average = sum / 4.0;

    cout << "Average score: " << average << endl;
}

int main(int argc, char const *argv[])
{
    int s1, s2, s3, s4, s5;

    getScore(s1);
    getScore(s2);
    getScore(s3);
    getScore(s4);
    getScore(s5);

    calcAverage(s1, s2, s3, s4, s5);

    return 0;
}

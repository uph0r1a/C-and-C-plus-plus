#include <iostream>
#include <iomanip>
using namespace std;

const int R = 4, C = 5;
using Mat = int[R][C];

void nhap(Mat m, const string &ten)
{
    cout << "Nhap " << ten << " (" << R << "x" << C << "):\n";
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cout << "  [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> m[i][j];
        }
}

void in(const Mat m, const string &ten)
{
    cout << ten << ":\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << setw(6) << m[i][j];
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    Mat A, B, S, D;
    nhap(A, "Ma tran A");
    nhap(B, "Ma tran B");

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            S[i][j] = A[i][j] + B[i][j];
            D[i][j] = A[i][j] - B[i][j];
        }

    cout << "\n";
    in(A, "Ma tran A");
    cout << "\n";
    in(B, "Ma tran B");
    cout << "\n";
    in(S, "Tong A+B");
    cout << "\n";
    in(D, "Hieu A-B");
    return 0;
}

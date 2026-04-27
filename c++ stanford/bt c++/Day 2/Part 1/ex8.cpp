#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const int N = 4;
    int mat[N][N];

    cout << "Nhap ma tran " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cout << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }

    cout << "\nMa tran:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(6) << mat[i][j];
        cout << "\n";
    }

    int cntPos = 0, cntNeg = 0;
    long long sumPos = 0, sumNeg = 0;

    cout << "\nPhan tu > 0: ";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] > 0)
            {
                cout << mat[i][j] << " ";
                cntPos++;
                sumPos += mat[i][j];
            }

    cout << "\nSo luong: " << cntPos << ", Tong: " << sumPos << "\n";

    cout << "Phan tu < 0: ";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] < 0)
            {
                cout << mat[i][j] << " ";
                cntNeg++;
                sumNeg += mat[i][j];
            }

    cout << "\nSo luong: " << cntNeg << ", Tong: " << sumNeg << "\n";
    return 0;
}

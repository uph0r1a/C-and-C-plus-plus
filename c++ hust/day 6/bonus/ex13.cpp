#include <iostream>
using namespace std;

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 1, 2},
        {1, 5, 2}};

    int row1, row2;
    cout << "Enter first row: ";
    cin >> row1;
    cout << "Enter second row: ";
    cin >> row2;

    for (int col = 0; col < 3; col++)
    {
        int temp = mat[row1][col];
        mat[row1][col] = mat[row2][col];
        mat[row2][col] = temp;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

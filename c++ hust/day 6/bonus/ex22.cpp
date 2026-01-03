#include <iostream>
using namespace std;

void swapRow(int mat[3][3])
{
    int row1, row2;

    cout << "Enter first row (0-2): ";
    cin >> row1;
    while (row1 < 0 || row1 > 2)
    {
        cout << "Invalid row number\nRe-enter a row between 0 and 2: ";
        cin >> row1;
    }

    cout << "Enter second row (0-2): ";
    cin >> row2;
    while (row2 < 0 || row2 > 2)
    {
        cout << "Invalid row number\nRe-enter a row between 0 and 2: ";
        cin >> row2;
    }

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
}

void swapColumn(int mat[3][3])
{
    int col1, col2;

    cout << "Enter first column (0-2): ";
    cin >> col1;
    while (col1 < 0 || col1 > 2)
    {
        cout << "Invalid column number\nRe-enter a column between 0 and 2: ";
        cin >> col1;
    }

    cout << "Enter second column (0-2): ";
    cin >> col2;
    while (col2 < 0 || col2 > 2)
    {
        cout << "Invalid column number\nRe-enter a column between 0 and 2: ";
        cin >> col2;
    }

    for (int row = 0; row < 3; row++)
    {
        int temp = mat[row][col1];
        mat[row][col1] = mat[row][col2];
        mat[row][col2] = temp;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 1, 2},
        {1, 5, 2}};

    cout << "Matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    swapRow(mat);
    cout << endl;
    swapColumn(mat);

    return 0;
}

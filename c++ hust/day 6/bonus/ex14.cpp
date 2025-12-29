#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 1, 2},
        {1, 5, 2}};

    int col1, col2;
    cout << "Enter first column: ";
    cin >> col1;
    cout << "Enter second column: ";
    cin >> col2;

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

    return 0;
}

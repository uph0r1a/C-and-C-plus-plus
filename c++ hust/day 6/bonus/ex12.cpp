#include <iostream>
#include <vector>
using namespace std;

void diagonal(vector<vector<int>> matrix)
{
    cout << "Main diagonal: ";
    for (int i = 0; i < matrix[0].size(); i++)
    {
        cout << matrix[i][i] << "\t";
    }
    cout << endl;

    cout << "Secondary diagonal: ";
    for (int i = 0; i < matrix[0].size(); i++)
    {
        cout << matrix[i][matrix.size() - i - 1] << "\t";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {3, 6, 8}};

    diagonal(matrix);

    return 0;
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 1, 2},
        {1, 5, 2}};

    int mostFrequent = mat[0][0], maxCount = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int count = 0;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (mat[i][j] == mat[x][y])
                    {
                        count++;
                    }
                }
            }

            if (count > maxCount)
            {
                maxCount = count;
                mostFrequent = mat[i][j];
            }
        }
    }

    cout << "Most frequent: " << mostFrequent << endl;
    cout << "Frequency: " << maxCount << endl;

    return 0;
}

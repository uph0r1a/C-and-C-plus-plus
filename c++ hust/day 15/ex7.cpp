#include <iostream>
using namespace std;

class TestScores
{
private:
    int *testScore;
    int size;

public:
    TestScores(int arr[], int s)
        : size(s)
    {
        testScore = new int[size];

        for (int i = 0; i < size; i++)
        {
            if (arr[i] > 100 || arr[i] < 0)
            {
                throw "Test score cannot be negative or greater than 100";
            }
            testScore[i] = arr[i];
        }
    }

    double averageScore() const
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += testScore[i];
        }

        return static_cast<double>(sum) / size;
    }

    ~TestScores()
    {
        delete[] testScore;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {0,100,0,100};
    TestScores score(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Average: " << score.averageScore() << endl;

    return 0;
}

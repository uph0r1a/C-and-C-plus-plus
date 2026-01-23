#include <iostream>
using namespace std;

class TestScores
{
public:
    TestScores()
    {
        testScore1 = 0;
        testScore2 = 0;
        testScore3 = 0;
    }

    void setTestScore1(float score1)
    {
        testScore1 = score1;
    }

    void setTestScore2(float score2)
    {
        testScore2 = score2;
    }

    void setTestScore3(float score3)
    {
        testScore3 = score3;
    }

    float getTestScore1() const
    {
        return testScore1;
    }

    float getTestScore2() const
    {
        return testScore2;
    }

    float getTestScore3() const
    {
        return testScore3;
    }

    float averageScore()
    {
        return (testScore1 + testScore2 + testScore3) / 3;
    }

private:
    float testScore1,
        testScore2,
        testScore3;
};

int main(int argc, char const *argv[])
{
    TestScores score;
    float tempScore[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter test score " << i + 1 << ": ";
        cin >> tempScore[i];
    }

    score.setTestScore1(tempScore[0]);
    score.setTestScore2(tempScore[1]);
    score.setTestScore3(tempScore[2]);

    cout << "Score 1: " << score.getTestScore1() << endl
         << "Score 2: " << score.getTestScore2() << endl
         << "Score 3: " << score.getTestScore3() << endl
         << "Average score: " << score.averageScore() << endl;

    return 0;
}

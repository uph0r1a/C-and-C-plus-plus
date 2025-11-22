#include <iostream>
using namespace std;

void getJudgeData(float &judge_score)
{
    cout << "Enter the judge's score: ";
    while (1)
    {
        cin >> judge_score;
        if (judge_score >= 0 && judge_score <= 10)
        {
            break;
        }
        cout << "Judge scoresmust not lower than 0 or higher than 10\nRe-enter the judge's score: ";
    }
}

float findLowest(float judge_score1, float judge_score2, float judge_score3, float judge_score4, float judge_score5)
{
    float min = judge_score1;
    if (judge_score2 < min)
    {
        min = judge_score2;
    }
    if (judge_score3 < min)
    {
        min = judge_score3;
    }
    if (judge_score4 < min)
    {
        min = judge_score4;
    }
    if (judge_score5 < min)
    {
        min = judge_score5;
    }
    return min;
}

float findHighest(float judge_score1, float judge_score2, float judge_score3, float judge_score4, float judge_score5)
{
    float max = judge_score1;
    if (judge_score2 > max)
    {
        max = judge_score2;
    }
    if (judge_score3 > max)
    {
        max = judge_score3;
    }
    if (judge_score4 > max)
    {
        max = judge_score4;
    }
    if (judge_score5 > max)
    {
        max = judge_score5;
    }
    return max;
}

void calcScore(float judge_score1, float judge_score2, float judge_score3, float judge_score4, float judge_score5)
{
    float max = findHighest(judge_score1, judge_score2, judge_score3, judge_score4, judge_score5);
    float min = findLowest(judge_score1, judge_score2, judge_score3, judge_score4, judge_score5);

    cout << "Average score: " << (judge_score1 + judge_score2 + judge_score3 + judge_score4 + judge_score5 - max - min) / 3;
}

int main(int argc, char const *argv[])
{
    float judge_score1, judge_score2, judge_score3, judge_score4, judge_score5;

    getJudgeData(judge_score1);
    getJudgeData(judge_score2);
    getJudgeData(judge_score3);
    getJudgeData(judge_score4);
    getJudgeData(judge_score5);

    calcScore(judge_score1, judge_score2, judge_score3, judge_score4, judge_score5);
    return 0;
}

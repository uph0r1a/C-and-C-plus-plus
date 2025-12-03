#include <iostream>
#include <fstream>
using namespace std;

typedef struct
{
    int number;
    char incorrect;
    char correct;
} Missed;

void Exam_grader()
{
    Missed missed[20];
    char correct[20], answer[20];
    int number_of_missed = 0, i = 0;

    ifstream f1("CorrectAnswers.txt");
    ifstream f2("StudentAnswers.txt");

    if (!f1 || !f2)
    {
        cout << "Cannot open file";
        return;
    }

    while ((f1 >> correct[i]) && (f2 >> answer[i]))
    {
        if (correct[i] != answer[i])
        {
            missed[number_of_missed].number = i + 1;
            missed[number_of_missed].incorrect = answer[i];
            missed[number_of_missed].correct = correct[i];
            number_of_missed++;
        }
        i++;
    }

    cout << "Questions missed: " << endl;
    for (int i = 0; i < number_of_missed; i++)
    {
        cout << missed[i].number << missed[i].incorrect << " Correct answer: " << missed[i].correct << endl;
    }

    cout << "The total number of questions missed: " << number_of_missed << endl
         << "The percentage of questions answered correctly: " << ((20.0 - number_of_missed) / 20.0) * 100.0 << "%" << endl
         << (((20 - number_of_missed) / 20) * 100 >= 70 ? "Passed" : "Failed");

    f1.close();
    f2.close();
}

int main(int argc, char const *argv[])
{
    Exam_grader();
    return 0;
}

#include <iostream>
#include <cctype>
using namespace std;

void Exam_check()
{
    char correct[20] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'}, answer[20];
    int count = 0;

    for (int i = 0; i < 20; i++)
    {
        cout << "Enter the answer of question " << i + 1 << ": ";
        while (1)
        {
            cin >> answer[i];
            if (toupper(answer[i]) == 'A' || toupper(answer[i]) == 'B' || toupper(answer[i]) == 'C' || toupper(answer[i]) == 'D')
            {
                break;
            }
            cout << "Only the letters A, B, C, or D accepted\nEnter the answer of question " << i + 1 << ": ";
        }

        if (answer[i] == correct[i])
        {
            count++;
        }
    }

    if (count >= 15)
    {
        cout << "Passed";
    }
    else
    {
        cout << "Failed";
    }
}

int main(int argc, char const *argv[])
{
    Exam_check();
    return 0;
}

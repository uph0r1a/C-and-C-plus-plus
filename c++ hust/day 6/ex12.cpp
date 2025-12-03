#include <iostream>
#include <string>
using namespace std;

void Grade()
{
    string names[5];
    char grades[5];
    double score[5][4];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter student " << i + 1 << "'s name: ";
        getline(cin, names[i]);
        double total_score = 0;
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter student " << i + 1 << "'s test scores number " << j + 1 << ": ";
            while (1)
            {
                cin >> score[i][j];
                if (score[i][j] >= 0 && score[i][j] <= 100)
                {
                    total_score += score[i][j];
                    break;
                }
                cout << "Test scores cannot be less than 0 or greater than 100\nRe-enter student " << i + 1 << "'s test scores number " << j + 1 << ": ";
            }
            cin.ignore();
        }
        if (total_score / 4 >= 90)
            grades[i] = 'A';
        else if (total_score / 4 >= 80)
            grades[i] = 'B';
        else if (total_score / 4 >= 70)
            grades[i] = 'C';
        else if (total_score / 4 >= 60)
            grades[i] = 'D';
        else
            grades[i] = 'F';
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << names[i] << ": " << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << "Score " << j + 1 << ": " << score[i][j] << endl;
        }
        cout << "Grade: " << grades[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    Grade();
    return 0;
}

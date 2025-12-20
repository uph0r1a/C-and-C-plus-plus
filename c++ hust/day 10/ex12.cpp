#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct
{
    string Name;
    int Idnum;
    float *Tests;
    float Average;
    char Grade;
} Student;

template <typename T>
void inputValidate(T &number)
{
    while (1)
    {
        cin >> number;
        if (number > 0)
        {
            cin.ignore();
            break;
        }
        cout << "This data must be positive\nRe-enter the data: ";
    }
}

void inputValidate(string &str)
{
    while (1)
    {
        getline(cin, str);
        if (!str.empty())
        {
            break;
        }
        cout << "Student name cannot be empty\nRe-enter student name: ";
    }
}
void CourseGrade(Student *&students)
{
    system("clear");
    int numStudents, numTests;

    cout << "Enter the number of student: ";
    inputValidate(numStudents);

    students = new Student[numStudents];

    cout << "Enter the number of test: ";
    inputValidate(numTests);

    for (int i = 0; i < numStudents; i++)
    {
        students[i].Tests = new float[numTests];
        float sum = 0;
        cout << "Student " << i + 1 << endl;

        cout << "Enter student " << i + 1 << " name: ";
        inputValidate(students[i].Name);

        cout << "Enter student " << i + 1 << " id number: ";
        inputValidate(students[i].Idnum);

        for (int j = 0; j < numTests; j++)
        {
            cout << "Enter student " << i + 1 << " test " << j + 1 << ": ";
            while (1)
            {
                cin >> students[i].Tests[j];
                if (students[i].Tests[j] >= 0 && students[i].Tests[j] <= 100)
                {
                    sum += students[i].Tests[j];
                    cin.ignore();
                    break;
                }
                cout << "Score must be in range of 0 to 100\nRe-enter the score: ";
            }
        }

        students[i].Average = sum / numTests;

        if (students[i].Average >= 91)
        {
            students[i].Grade = 'A';
        }
        else if (students[i].Average >= 81)
        {
            students[i].Grade = 'B';
        }
        else if (students[i].Average >= 71)
        {
            students[i].Grade = 'C';
        }
        else if (students[i].Average >= 61)
        {
            students[i].Grade = 'D';
        }
        else
        {
            students[i].Grade = 'F';
        }
    }

    cout << "------------------------------------------------------------" << endl;
    cout << left << "|" << setw(15) << "Name" << "|" << setw(10) << "Id Number" << "|" << setw(15) << "Average Score" << "|" << setw(15) << "Course Grade" << "|" << endl;
    cout << "|----------------------------------------------------------|" << endl;

    for (int i = 0; i < numStudents; i++)
    {
        cout << left
             << "|" << setw(15) << students[i].Name
             << "|" << setw(10) << students[i].Idnum
             << "|" << setw(15) << students[i].Average
             << "|" << setw(15) << students[i].Grade
             << "|" << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < numStudents; i++)
    {
        delete[] students[i].Tests;
    }
    delete[] students;
}

int main(int argc, char const *argv[])
{
    Student *student = nullptr;
    CourseGrade(student);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

void Sort(int arrScore[], string arrName[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arrScore[j] > arrScore[j + 1])
            {
                int tempscore = arrScore[j];
                arrScore[j] = arrScore[j + 1];
                arrScore[j + 1] = tempscore;

                string tempname = arrName[j];
                arrName[j] = arrName[j + 1];
                arrName[j + 1] = tempname;
            }
        }
    }
}

float Average(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<float>(sum) / static_cast<float>(size);
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter a array size: ";
    while (1)
    {
        cin >> size;
        if (size >= 0)
        {
            break;
        }
        cout << "Array size cannot be negative\nRe-enter a array size: ";
    }

    int *arrScore = new int[size];
    string *arrName = new string[size];

    for (int i = 0; i < size; i++)
    {
        cin.ignore();
        cout << "Enter the student name number " << i + 1 << ": ";
        getline(cin, arrName[i]);

        cout << "Enter score number " << i + 1 << ": ";
        while (1)
        {
            cin >> arrScore[i];
            if (arrScore[i] >= 0)
            {
                break;
            }
            cout << "Test score cannot be negative\nEnter score number " << i + 1 << ": ";
        }
    }

    Sort(arrScore, arrName, size);

    for (int i = 0; i < size; i++)
    {
        cout << "Student name " << i + 1 << ": " << arrName[i] << endl
             << "Student score " << i + 1 << ": " << arrScore[i] << endl;
    }

    float average = Average(arrScore, size);

    cout << "Sort score array: " << endl;
    for (int i = 0; i < size; i++)
    {

        cout << "Name: " << arrName[i] << endl
             << "Score: " << arrScore[i] << endl;
    }

    cout << "Average score: " << average << endl;

    delete[] arrScore;
    delete[] arrName;

    return 0;
}

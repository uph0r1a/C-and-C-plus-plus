#include <iostream>
#include <string>
using namespace std;

int main()
{
    int number_of_student;

    cout << "Enter the number of students: ";
    while (true)
    {
        cin >> number_of_student;
        if (number_of_student >= 1 && number_of_student <= 25)
            break;
        cout << "Invalid input. Enter a number between 1 and 25: ";
    }

    cin.ignore();

    string firstName, lastName, inputName;

    cout << "Enter student names:\n";

    for (int i = 0; i < number_of_student; i++)
    {
        getline(cin, inputName);

        if (i == 0)
        {
            firstName = inputName;
            lastName = inputName;
        }
        else
        {
            if (inputName < firstName)
                firstName = inputName;
            if (inputName > lastName)
                lastName = inputName;
        }
    }

    cout << "\nStudent at the front of the line: " << firstName << endl;
    cout << "Student at the end of the line: " << lastName << endl;

    return 0;
}

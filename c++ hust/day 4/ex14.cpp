#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int number_of_student;
    string name_input, name_output;

    cout << "Enter the number of student: ";
    while (1)
    {
        cin >> number_of_student;
        if (number_of_student >= 1 && number_of_student <= 25)
        {
            break;
        }
        cout << " Do not accept a number less than 1 or greater than 25 for the number of students.\n";
    }
    string *all_name = new string[number_of_student];

    cin.ignore();

    ofstream MyWriteFile("filename.txt");

    cout << "Enter the student name: ";
    for (int i = 0; i <= number_of_student; i++)
    {
        getline(cin, name_input);
        MyWriteFile << name_input << "\n";
    }

    MyWriteFile.close();

    ifstream MyReadFile("filename.txt");

    int i = 0;

    while (getline(MyReadFile, name_output))
    {
        all_name[i] = name_output;
        i++;
    }
a
    MyReadFile.close();
    delete[] all_name;
}

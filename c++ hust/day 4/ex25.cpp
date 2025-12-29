#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string filename;
    cout << "Enter the filename containing student names: ";
    cin >> filename;

    ifstream inFile(filename);

    if (!inFile)
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string firstName, lastName, name;
    bool firstEntry = true;

    while (getline(inFile, name))
    {
        if (firstEntry)
        {
            firstName = lastName = name;
            firstEntry = false;
        }
        else
        {
            if (name < firstName)
                firstName = name;
            if (name > lastName)
                lastName = name;
        }
    }

    inFile.close();

    if (firstEntry)
    {
        cout << "No student names found in the file." << endl;
    }
    else
    {
        cout << "\nStudent at the front of the line: " << firstName << endl;
        cout << "Student at the end of the line: " << lastName << endl;
    }

    return 0;
}

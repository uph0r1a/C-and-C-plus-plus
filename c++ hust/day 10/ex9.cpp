#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    string name, telephoneNumber, speakingTopic;
    float fee;
} Speaker;

void inputValidation(string &string)
{
    while (1)
    {
        getline(cin, string);
        if (!string.empty())
        {
            break;
        }
        cout << "Data cannot be empty\nRe-enter data: ";
    }
}

void inputValidation(float &fee)
{
    while (1)
    {
        cin >> fee;
        if (fee >= 0)
        {
            break;
        }
        cout << "Fee cannot be negative\nRe-enter fee: ";
    }
}

void inputSpeaker(Speaker speaker[10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Speaker " << i + 1 << endl;
        cout << "Enter speaker " << i + 1 << " name: ";
        inputValidation(speaker[i].name);

        cout << "Enter speaker " << i + 1 << " telephone number: ";
        inputValidation(speaker[i].telephoneNumber);

        cout << "Enter speaker " << i + 1 << " speaking topic: ";
        inputValidation(speaker[i].speakingTopic);

        cout << "Enter speaker " << i + 1 << " fee required: ";
        inputValidation(speaker[i].fee);
        cin.ignore();
    }
}

void changeSpeaker(Speaker speaker[10])
{
    int search, choice;
    bool loop = true;
    string item;
    cout << "Enter the speaker number to change (1-10): ";
    cin >> search;

    cout << "Name: " << speaker[search - 1].name << endl
         << "Telephone number: " << speaker[search - 1].telephoneNumber << endl
         << "Speaking topic: " << speaker[search - 1].speakingTopic << endl
         << "Fee required: " << speaker[search - 1].fee << endl;

    do
    {
        cout << "Enter a number of element to change" << endl
             << "1)Name" << endl
             << "2)Telephone Number" << endl
             << "3)Speaking Topic" << endl
             << "4)Fee Required" << endl
             << "0)Done";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter speaker " << search << " name: ";
            inputValidation(speaker[search - 1].name);
            break;
        case 2:
            cout << "Enter speaker " << search << " telephone number: ";
            inputValidation(speaker[search - 1].telephoneNumber);
            break;
        case 3:
            cout << "Enter speaker " << search << " speaking topic: ";
            inputValidation(speaker[search - 1].speakingTopic);
            break;
        case 4:
            cout << "Enter speaker " << search << " fee require: ";
            inputValidation(speaker[search - 1].fee);
            break;
        case 0:
            loop = false;
            break;
        default:
            cout << "Invalid choice\nRe-enter your choice: ";
            break;
        }
    } while (loop);
}

void displaySpeaker(Speaker speaker[10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Speaker " << i + 1 << endl
             << "Name: " << speaker[i].name << endl
             << "Telephone number: " << speaker[i].telephoneNumber << endl
             << "Speaking Topic: " << speaker[i].speakingTopic << endl
             << "Fee Required: " << speaker[i].fee << endl;
    }
}

int main(int argc, char const *argv[])
{
    Speaker speaker[10];
    bool isEmpty = true, loop = true;
    int choice;

    do
    {
        system("clear");
        cout << "Speaker's Bureau" << endl
             << "1)Input data" << endl
             << "2)Edit data" << endl
             << "3)Display data" << endl
             << "0)Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputSpeaker(speaker);
            isEmpty = false;
            break;
        case 2:
            if (!isEmpty)
            {
                changeSpeaker(speaker);
            }
            else
            {
                cout << "No speaker to change";
            }
            break;
        case 3:
            if (!isEmpty)
            {
                displaySpeaker(speaker);
            }
            else
            {
                cout << "No speaker to display";
            }
            break;
        case 0:
            loop = false;
            break;
        default:
            cout << "Invalid choice\nRe-enter the choice: ";
            break;
        }

    } while (loop);

    return 0;
}

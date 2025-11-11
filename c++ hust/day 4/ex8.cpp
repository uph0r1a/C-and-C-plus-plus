#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));
    int a, b, answer, choice, flag = 1;
    cout << "Menu\n";
    cout << "1)Addition\n";
    cout << "2)Subtraction\n";
    cout << "3)Multiplication\n";
    cout << "4)Division\n";
    cout << "5)Exit\n";

    do
    {
        a = rand() % 100 + 1;
        b = rand() % 100 + 1;
        cout << "Pick a problem: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << a << endl;
            cout << "+" << b << "\n";
            cout << "------" << endl;
            cout << "Enter the answer: ";
            cin >> answer;
            if (a + b == answer)
            {
                cout << "Congratulations\n";
            }
            else
            {
                cout << a + b << "\n";
            }
            break;
        case 2:
            cout << a << endl;
            cout << "-" << b << "\n";
            cout << "------" << endl;
            cout << "Enter the answer: ";
            cin >> answer;
            if (a - b == answer)
            {
                cout << "Congratulations\n";
            }
            else
            {
                cout << a - b << "\n";
            }
            break;
        case 3:
            cout << a << endl;
            cout << "*" << b << "\n";
            cout << "------" << endl;
            cout << "Enter the answer: ";
            cin >> answer;
            if (a * b == answer)
            {
                cout << "Congratulations\n";
            }
            else
            {
                cout << a * b << "\n";
            }
            break;
        case 4:
            cout << a << endl;
            cout << "/" << b << "\n";
            cout << "------" << endl;
            cout << "Enter the answer: ";
            cin >> answer;
            if (static_cast<float>(a) / b == answer)
            {
                cout << "Congratulations\n";
            }
            else
            {
                cout << static_cast<float>(a / b) << "\n";
            }
            break;
        case 5:
            flag = 0;
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (flag);

    return 0;
}

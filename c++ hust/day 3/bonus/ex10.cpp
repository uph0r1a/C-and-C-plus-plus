#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a, b;
    int flag = 1;
    char operator_input;

    while (flag)
    {
        cout << "Enter a: ";
        ;
        cin >> a;
        cout << "Enter b: ";
        ;
        cin >> b;
        cout << "Enter operator: ";
        cin >> operator_input;

        switch (operator_input)
        {
        case '+':
            cout << "a + b = " << a + b;
            flag = 0;
            break;
        case '-':
            cout << "a - b = " << a - b;
            flag = 0;
            break;
        case '*':
            cout << "a * b = " << a * b;
            flag = 0;
            break;
        case '/':
            if (b != 0)
            {
                cout << "a / b = " << a / b;
                flag = 0;
                break;
            }

            cout << "Cannnot divide by 0\n";
            break;
        default:
            break;
        }
    }

    return 0;
}

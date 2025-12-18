#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    string name, address, city, state, telephoneNumber;
    int zip, dateLastPayment;
    float accountbalance;
} CustomerAccount;

void inputValidate(string &string)
{
    while (1)
    {
        getline(cin, string);
        if (!string.empty())
        {
            break;
        }
        cout << "Data cannot be empty\nRe-enter the data: ";
    }
}

void inputValidate(float &number)
{
    while (1)
    {
        cin >> number;
        if (number >= 0)
        {
            break;
        }
        cout << "Account balance cannot be negative\nRe-enter the account balance: ";
    }
}

void customerAccount(CustomerAccount accounts[10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Customer " << i + 1 << endl;
        cout << "Enter the customer " << i << " name: ";
        inputValidate(accounts[i].name);

        cout << "Enter the customer " << i << " address: ";
        inputValidate(accounts[i].address);

        cout << "Enter the customer " << i << " city: ";
        inputValidate(accounts[i].city);

        cout << "Enter the customer " << i << " state: ";
        inputValidate(accounts[i].state);

        cout << "Enter the customer " << i << " ZIP: ";
        while (1)
        {
            cin >> accounts[i].zip;
            if (accounts[i].zip >= 10000 && accounts[i].zip <= 99999)
            {
                break;
            }
            cout << "Zip must have 5 characters\nRe-enter the customer " << i << " ZIP: ";
        }

        cout << "Enter the customer " << i << " telephone number: ";
        inputValidate(accounts[i].telephoneNumber);

        cout << "Enter the customer " << i << " account balance: ";
        inputValidate(accounts[i].accountbalance);

        cout << "Enter the customer " << i << " date of last payment: ";
        while (1)
        {
            cin >> accounts[i].dateLastPayment;
            if (accounts[i].dateLastPayment >= 1 && accounts[i].dateLastPayment <= 31)
            {
                break;
            }
            cout << "Invalid date of last payment\nRe-enter the customer " << i << " date of last payment: ";
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Customer " << i + 1 << ": " << endl
             << "Name: " << accounts[i].name << endl
             << "Address: " << accounts[i].address << endl
             << "City: " << accounts[i].city << endl
             << "State: " << accounts[i].state << endl
             << "ZIP: " << accounts[i].zip << endl
             << "Telephone number: " << accounts[i].telephoneNumber << endl
             << "Account Balance: " << accounts[i].accountbalance << endl
             << "Date of Last Payment: " << accounts[i].dateLastPayment << endl;
    }
}

void searchAccount(CustomerAccount accounts[10], string search)
{
    bool found = false;

    for (int i = 0; i < 10; i++)
    {
        if (accounts[i].name.find(search) != string::npos)
        {
            found = true;
            cout << "Name: " << accounts[i].name << endl
                 << "Address: " << accounts[i].address << endl
                 << "City: " << accounts[i].city << endl
                 << "State: " << accounts[i].state << endl
                 << "ZIP: " << accounts[i].zip << endl
                 << "Telephone number: " << accounts[i].telephoneNumber << endl
                 << "Account Balance: " << accounts[i].accountbalance << endl
                 << "Date of Last Payment: " << accounts[i].dateLastPayment << endl;
        }
    }

    if (!found)
    {
        cout << "No account found" << endl;
    }
}

int main(int argc, char const *argv[])
{
    CustomerAccount accounts[10];
    int choice;
    customerAccount(accounts);

    cout << "Do you want to search for account(1)Yes (Press any other key)No: ";
    cin >> choice;

    if (choice == 1)
    {
        string search;
        getline(cin, search);
        searchAccount(accounts, search);
    }

    return 0;
}

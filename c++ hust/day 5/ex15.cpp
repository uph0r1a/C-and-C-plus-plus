#include <iostream>
#include <string>
using namespace std;

float Total_charge(int &number_of_day, float &daily_rate, float &medication_charge, float &service_charge)
{
    cout << "Enter the number of day: ";
    while (1)
    {
        cin >> number_of_day;
        if (number_of_day >= 0)
        {
            break;
        }
        cout << "Number of day cannot be negative\nRe-enter the number of day: ";
    }

    cout << "Enter the daily rate: ";
    while (1)
    {
        cin >> daily_rate;
        if (daily_rate >= 0)
        {
            break;
        }
        cout << "Daily rate cannot be negative\nRe-enter the daily rate: ";
    }

    cout << "Enter the medication charge: ";
    while (1)
    {
        cin >> medication_charge;
        if (medication_charge >= 0)
        {
            break;
        }
        cout << "Medication charge cannot be negative\nRe-enter the medication charge: ";
    }

    cout << "Enter the service charge: ";
    while (1)
    {
        cin >> service_charge;
        if (service_charge >= 0)
        {
            break;
        }
        cout << "Service charge cannot be negative\nRe-enter the service charge: ";
    }

    return daily_rate * number_of_day + medication_charge + service_charge;
}

float Total_charge(float &medication_charge, float &service_charge)
{
    cout << "Enter the medication charge: ";
    while (1)
    {
        cin >> medication_charge;
        if (medication_charge >= 0)
        {
            break;
        }
        cout << "Medication charge cannot be negative\nRe-enter the medication charge: ";
    }

    cout << "Enter the service charge: ";
    while (1)
    {
        cin >> service_charge;
        if (service_charge >= 0)
        {
            break;
        }
        cout << "Service charge cannot be negative\nRe-enter the service charge: ";
    }
    return medication_charge + service_charge;
}

int main(int argc, char const *argv[])
{
    string choice;
    int number_of_day;
    float daily_rate, medication_charge, service_charge, total_charge;

    cout << "Are you an in-patient or an out-patient: ";
    while (1)
    {
        getline(cin, choice);

        if (choice == "in-patient")
        {
            total_charge = Total_charge(number_of_day, daily_rate, medication_charge, service_charge);
            cout << "Total charge: " << total_charge;
            break;
        }
        else if (choice == "out-patient")
        {
            total_charge = Total_charge(medication_charge, service_charge);
            cout << "Total charge: " << total_charge;
            break;
        }
        else
        {
            cout << "Invalid choice\nRe-enter the choice: ";
        }
    }

    return 0;
}

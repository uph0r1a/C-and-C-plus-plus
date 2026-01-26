#include <iostream>
#include <iomanip>
using namespace std;

class PatientAccount
{
private:
    int days;
    double dailyRate;
    double totalCharges;

public:
    PatientAccount(int d = 0)
    {
        days = d;
        dailyRate = 20.0;
        totalCharges = 0.0;
    }

    void setDays(int d)
    {
        days = d;
    }

    void addCharge(double amount)
    {
        totalCharges += amount;
    }

    void addDailyCharges()
    {
        totalCharges += days * dailyRate;
    }

    double getTotalCharges() const
    {
        return totalCharges;
    }
};

class Surgery
{
private:
    double charges[5] = {1500, 2300, 1800, 3200, 2700};

public:
    void displayMenu() const
    {
        cout << "\n--- Surgery Menu ---\n";
        for (int i = 0; i < 5; i++)
            cout << i + 1 << ". Surgery Type " << i + 1
                 << " ($" << charges[i] << ")\n";
        cout << "0. Done selecting surgeries\n";
    }

    double getCharge(int choice) const
    {
        if (choice >= 1 && choice <= 5)
            return charges[choice - 1];
        return 0.0;
    }
};

class Pharmacy
{
private:
    double charges[5] = {50, 120, 80, 200, 150};

public:
    void displayMenu() const
    {
        cout << "\n--- Pharmacy Menu ---\n";
        for (int i = 0; i < 5; i++)
            cout << i + 1 << ". Medication " << i + 1
                 << " ($" << charges[i] << ")\n";
        cout << "0. Done selecting medications\n";
    }

    double getCharge(int choice) const
    {
        if (choice >= 1 && choice <= 5)
            return charges[choice - 1];
        return 0.0;
    }
};

int main(int argc, char const *argv[])
{
    PatientAccount patient;
    Surgery surgery;
    Pharmacy pharmacy;

    int days;
    cout << "Enter number of days in hospital: ";
    while (!(cin >> days) || days <= 0)
    {
        cout << "Invalid input. Enter days again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    patient.setDays(days);
    patient.addDailyCharges();

    int choice;

    do
    {
        surgery.displayMenu();
        cout << "Choose surgery: ";
        cin >> choice;

        if (choice != 0)
            patient.addCharge(surgery.getCharge(choice));

    } while (choice != 0);

    do
    {
        pharmacy.displayMenu();
        cout << "Choose medication: ";
        cin >> choice;

        if (choice != 0)
            patient.addCharge(pharmacy.getCharge(choice));

    } while (choice != 0);

    cout << fixed << setprecision(2);
    cout << "\n===== FINAL BILL =====\n";
    cout << "Total Charges: $" << patient.getTotalCharges() << endl;

    return 0;
}
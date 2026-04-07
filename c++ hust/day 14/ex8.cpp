#include <iostream>
using namespace std;

class PersonData
{
private:
    string lastName, firstName, address, city, state, zip, phone;

public:
    void setLastName(string lName)
    {
        lastName = lName;
    }

    void setFirstName(string fName)
    {
        firstName = fName;
    }

    void setAddress(string a)
    {
        address = a;
    }

    void setCity(string c)
    {
        city = c;
    }

    void setState(string s)
    {
        state = s;
    }

    void setZip(string z)
    {
        zip = z;
    }

    void setPhone(string p)
    {
        phone = p;
    }

    string getLastName() const
    {
        return lastName;
    }

    string getFirstName() const
    {
        return firstName;
    }

    string getAddress() const
    {
        return address;
    }

    string getCity() const
    {
        return city;
    }

    string getState() const
    {
        return state;
    }

    string getZip() const
    {
        return zip;
    }

    string getPhone() const
    {
        return phone;
    }
};

class CustomerData : public PersonData
{
private:
    int customerNumber;
    bool mailingList;

public:
    void setCustomerNumber(int num)
    {
        customerNumber = num;
    }

    void setMailingList(bool mail)
    {
        mailingList = mail;
    }

    int getCustomerNumber()
    {
        return customerNumber;
    }

    bool getMailingList()
    {
        return mailingList;
    }
};

class PreferredCustomer : public CustomerData
{
private:
    double purchasesAmount, discountLevel;

public:
    void setPurchasesAmount(double amount)
    {
        if (amount >= 0)
        {
            purchasesAmount = amount;
        }
    }

    void setdiscountLevel()
    {
        if (purchasesAmount >= 2000)
        {
            discountLevel = 10;
        }
        else if (purchasesAmount >= 1500)
        {
            discountLevel = 7;
        }
        else if (purchasesAmount >= 1000)
        {
            discountLevel = 6;
        }
        else if (purchasesAmount >= 500)
        {
            discountLevel = 5;
        }
        else
        {
            discountLevel = 0;
        }
    }

    double getPurchasesAmount()
    {
        return purchasesAmount;
    }

    double getDiscountLevel()
    {
        return discountLevel;
    }
};

int main(int argc, char const *argv[])
{
    PreferredCustomer customer;
    string lastName, firstName, address, city, state, zip, phone;
    int customerNumber, mailingList;
    double purchasesAmount;

    cout << "Enter customer last name: ";
    cin >> lastName;
    customer.setLastName(lastName);

    cout << "Enter customer first name: ";
    cin >> firstName;
    customer.setFirstName(firstName);

    cout << "Enter customer address: ";
    cin >> address;
    customer.setAddress(address);

    cout << "Enter customer city: ";
    cin >> city;
    customer.setCity(city);

    cout << "Enter customer state: ";
    cin >> state;
    customer.setState(state);

    cout << "Enter customer zip: ";
    cin >> zip;
    customer.setZip(zip);

    cout << "Enter customer phone: ";
    cin >> phone;
    customer.setPhone(phone);

    cout << "Enter customer number: ";
    cin >> customerNumber;
    customer.setCustomerNumber(customerNumber);

    cout << "Enter customer mailling list: ";
    cin >> mailingList;
    customer.setMailingList(mailingList == 0 ? false : true);

    cout << "Enter customer purchased amount: ";
    cin >> purchasesAmount;
    customer.setPurchasesAmount(purchasesAmount);
    customer.setdiscountLevel();

    cout << "Customer Number: " << customer.getCustomerNumber() << endl
         << "Name: " << customer.getLastName() << " " << customer.getFirstName() << endl
         << "Address: " << customer.getAddress() << endl
         << "City: " << customer.getCity() << endl
         << "State: " << customer.getState() << endl
         << "Zip: " << customer.getZip() << endl
         << "Phone: " << customer.getPhone() << endl
         << "Mailing List: ";
    customer.getMailingList() ? cout << "yes" : cout << "no";

    cout << endl
         << "Purchased Amount: " << customer.getPurchasesAmount() << endl
         << "Discount Level: " << customer.getDiscountLevel() << endl;

    return 0;
}

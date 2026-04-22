#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int empId;
        int hours;
        double payRate;
        double wages;
        Node *next;
    };

    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(int id, int hrs, double rate)
    {
        Node *newNode = new Node;
        newNode->empId = id;
        newNode->hours = hrs;
        newNode->payRate = rate;
        newNode->wages = hrs * rate;
        newNode->next = nullptr;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void display() const
    {
        Node *ptr = head;

        while (ptr)
        {
            cout << "Employee number: " << ptr->empId << endl;
            cout << "Gross wages: " << ptr->wages << endl;
            cout << "------------------------" << endl;
            ptr = ptr->next;
        }
    }
};

void Payroll()
{
    int empIdList[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};

    LinkedList list;

    int n;
    cout << "How many employees? ";
    cin >> n;

    if (n > 7)
        n = 7;

    for (int i = 0; i < n; i++)
    {
        int hours;
        double payRate;

        cout << "\nEmployee number " << empIdList[i] << ":\n";

        cout << "Enter hours: ";
        while (true)
        {
            cin >> hours;
            if (hours >= 0)
                break;
            cout << "Hours cannot be negative. Re-enter: ";
        }

        cout << "Enter pay rate: ";
        while (true)
        {
            cin >> payRate;
            if (payRate >= 15)
                break;
            cout << "Pay rate cannot be less than 15. Re-enter: ";
        }

        list.append(empIdList[i], hours, payRate);
    }

    cout << "\n===== PAYROLL REPORT =====\n";
    list.display();
}

int main(int argc, char const *argv[])
{
    Payroll();
    return 0;
}
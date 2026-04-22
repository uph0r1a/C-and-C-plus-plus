#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        double value;
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

    void append(double value)
    {
        Node *newNode = new Node{value, nullptr};

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

    double getTotal() const
    {
        double sum = 0;
        Node *ptr = head;

        while (ptr)
        {
            sum += ptr->value;
            ptr = ptr->next;
        }

        return sum;
    }

    void getMinMax(int &minMonth, int &maxMonth) const
    {
        if (!head)
            return;

        Node *ptr = head;
        double min = ptr->value;
        double max = ptr->value;

        int index = 1;
        minMonth = maxMonth = 1;

        int currentMonth = 1;

        while (ptr)
        {
            if (ptr->value > max)
            {
                max = ptr->value;
                maxMonth = currentMonth;
            }

            if (ptr->value < min)
            {
                min = ptr->value;
                minMonth = currentMonth;
            }

            ptr = ptr->next;
            currentMonth++;
        }
    }

    int size() const
    {
        int count = 0;
        Node *ptr = head;

        while (ptr)
        {
            count++;
            ptr = ptr->next;
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList rainfall;

    int months;
    cout << "How many months of rainfall data? ";
    cin >> months;

    for (int i = 0; i < months; i++)
    {
        double value;

        cout << "Enter rainfall for month " << i + 1 << ": ";

        while (true)
        {
            cin >> value;

            if (value >= 0)
                break;

            cout << "Rainfall cannot be negative. Re-enter month " << i + 1 << ": ";
        }

        rainfall.append(value);
    }

    double total = rainfall.getTotal();
    double average = total / months;

    int minMonth, maxMonth;
    rainfall.getMinMax(minMonth, maxMonth);

    cout << "\nTotal rainfall: " << total << endl;
    cout << "Average rainfall: " << average << endl;
    cout << "Highest month: " << maxMonth << endl;
    cout << "Lowest month: " << minMonth << endl;

    return 0;
}
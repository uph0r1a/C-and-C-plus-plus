#include <iostream>
using namespace std;

class Inventory
{
private:
    int serialNum;
    string manufactDate;
    int lotNum;

public:
    Inventory(int s = 0, string d = "", int l = 0)
    {
        serialNum = s;
        manufactDate = d;
        lotNum = l;
    }

    void setData(int s, string d, int l)
    {
        serialNum = s;
        manufactDate = d;
        lotNum = l;
    }

    void display() const
    {
        cout << "Serial #: " << serialNum
             << ", Date: " << manufactDate
             << ", Lot #: " << lotNum << endl;
    }
};

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <class T>
class DynamicStack
{
private:
    Node<T> *top;

public:
    DynamicStack()
    {
        top = nullptr;
    }

    ~DynamicStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!\n";
            return T();
        }

        Node<T> *temp = top;
        T value = top->data;
        top = top->next;
        delete temp;

        return value;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            temp->data.display();
            temp = temp->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    DynamicStack<Inventory> stack;
    int choice;

    do
    {
        cout << "\n===== INVENTORY MENU =====\n";
        cout << "1. Add part to inventory\n";
        cout << "2. Take part from inventory\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int serial, lot;
            string date;

            cout << "Enter Serial Number: ";
            cin >> serial;

            cout << "Enter Manufacture Date: ";
            cin >> date;

            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory item(serial, date, lot);
            stack.push(item);

            cout << "Part added to inventory.\n";
        }
        else if (choice == 2)
        {
            if (stack.isEmpty())
            {
                cout << "Inventory is empty.\n";
            }
            else
            {
                Inventory item = stack.pop();
                cout << "Removed part:\n";
                item.display();
            }
        }

    } while (choice != 3);

    cout << "\n=== Remaining Inventory ===\n";
    if (stack.isEmpty())
    {
        cout << "No items left.\n";
    }
    else
    {
        stack.display();
    }

    return 0;
}

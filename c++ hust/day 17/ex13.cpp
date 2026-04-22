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
class DynamicQueue
{
private:
    Node<T> *front;
    Node<T> *rear;

public:
    DynamicQueue()
    {
        front = rear = nullptr;
    }

    ~DynamicQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return T();
        }

        Node<T> *temp = front;
        T value = front->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        return value;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void display()
    {
        Node<T> *temp = front;
        while (temp != nullptr)
        {
            temp->data.display();
            temp = temp->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    DynamicQueue<Inventory> queue;
    int choice;

    do
    {
        cout << "\n===== INVENTORY MENU (QUEUE) =====\n";
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
            queue.enqueue(item);

            cout << "Part added to inventory.\n";
        }
        else if (choice == 2)
        {
            if (queue.isEmpty())
            {
                cout << "Inventory is empty.\n";
            }
            else
            {
                Inventory item = queue.dequeue();
                cout << "Removed part:\n";
                item.display();
            }
        }

    } while (choice != 3);

    cout << "\n=== Remaining Inventory ===\n";
    if (queue.isEmpty())
    {
        cout << "No items left.\n";
    }
    else
    {
        queue.display();
    }

    return 0;
}

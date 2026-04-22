#include <iostream>
using namespace std;

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
        front = nullptr;
        rear = nullptr;
    }

    ~DynamicQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
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

        cout << value << " inserted into queue\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Nothing to remove\n";
            return;
        }

        Node<T> *temp = front;
        cout << front->data << " removed from queue\n";
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }
        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue (front -> rear): ";
        Node<T> *temp = front;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int size()
    {
        int count = 0;
        Node<T> *temp = front;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    DynamicQueue<int> q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    q1.display();

    cout << "Front element: " << q1.peek() << endl;
    cout << "Size: " << q1.size() << endl;

    q1.dequeue();
    q1.dequeue();

    q1.display();

    cout << "\n=== String Queue ===\n";
    DynamicQueue<string> q2;

    q2.enqueue("CS101");
    q2.enqueue("Data Structures");
    q2.enqueue("C++ Templates");

    q2.display();

    cout << "Front element: " << q2.peek() << endl;

    q2.dequeue();

    q2.display();

    cout << "Size: " << q2.size() << endl;

    return 0;
}

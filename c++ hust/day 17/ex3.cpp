#include <iostream>
using namespace std;

template <class T>
class StaticQueue
{
private:
    static const int MAX = 5;
    T arr[MAX];
    int front;
    int rear;

public:
    StaticQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == MAX - 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(T value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;
        cout << value << " inserted into queue\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Nothing to remove\n";
            return;
        }

        cout << arr[front] << " removed from queue\n";
        front++;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T();
        }
        return arr[front];
    }

    int size()
    {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue (front -> rear): ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    StaticQueue<int> q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    q1.display();

    cout << "Front element: " << q1.peek() << endl;
    cout << "Size: " << q1.size() << endl;

    q1.dequeue();
    q1.dequeue();

    q1.display();

    cout << "\n=== String Queue ===\n";
    StaticQueue<string> q2;

    q2.enqueue("A");
    q2.enqueue("B");
    q2.enqueue("C");

    q2.display();

    cout << "Front element: " << q2.peek() << endl;

    q2.dequeue();
    q2.display();

    return 0;
}

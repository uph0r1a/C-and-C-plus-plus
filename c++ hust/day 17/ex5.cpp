#include <iostream>
#include <queue>
using namespace std;

class DynIntStack
{
private:
    struct StackNode
    {
        int value;
        StackNode *next;
    };

    StackNode *top;

public:
    DynIntStack()
    {
        top = nullptr;
    }

    ~DynIntStack()
    {
        StackNode *nodePtr = top;
        while (nodePtr != nullptr)
        {
            StackNode *nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void push(int num)
    {
        try
        {
            StackNode *newNode = new StackNode;
            newNode->value = num;

            newNode->next = top;
            top = newNode;
        }
        catch (bad_alloc &)
        {
            cout << "Memory allocation failed. Stack push aborted.\n";
        }
    }

    void pop(int &num)
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        StackNode *temp = top;
        num = top->value;
        top = top->next;
        delete temp;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class DynIntQueue
{
private:
    struct QueueNode
    {
        int value;
        QueueNode *next;
    };

    QueueNode *front;
    QueueNode *rear;
    int numItems;

public:
    DynIntQueue()
    {
        front = nullptr;
        rear = nullptr;
        numItems = 0;
    }

    ~DynIntQueue()
    {
        clear();
    }

    void enqueue(int num)
    {
        try
        {
            QueueNode *newNode = new QueueNode;
            newNode->value = num;
            newNode->next = nullptr;

            if (isEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }

            numItems++;
        }
        catch (bad_alloc &)
        {
            cout << "Memory allocation failed. Enqueue aborted.\n";
        }
    }

    void dequeue(int &num)
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        QueueNode *temp = front;
        num = front->value;
        front = front->next;

        delete temp;
        numItems--;

        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    bool isEmpty()
    {
        return numItems == 0;
    }

    void clear()
    {
        int dummy;

        while (!isEmpty())
        {
            dequeue(dummy);
        }
    }
};

int main(int argc, char const *argv[])
{
    DynIntStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    int value;

    stack.pop(value);
    cout << "Popped from stack: " << value << endl;

    stack.pop(value);
    cout << "Popped from stack: " << value << endl;

    stack.pop(value);
    cout << "Popped from stack: " << value << endl;

    stack.pop(value);

    DynIntQueue queue;

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    queue.dequeue(value);
    cout << "Dequeued from queue: " << value << endl;

    queue.dequeue(value);
    cout << "Dequeued from queue: " << value << endl;

    queue.dequeue(value);
    cout << "Dequeued from queue: " << value << endl;

    queue.dequeue(value);

    return 0;
}

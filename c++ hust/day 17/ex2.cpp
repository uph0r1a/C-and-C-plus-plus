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

        cout << value << " pushed\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop\n";
            return;
        }

        Node<T> *temp = top;
        cout << top->data << " popped\n";
        top = top->next;
        delete temp;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T();
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int size()
    {
        int count = 0;
        Node<T> *temp = top;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top -> bottom): ";
        Node<T> *temp = top;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    DynamicStack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);

    intStack.display();

    cout << "Top: " << intStack.peek() << endl;
    cout << "Size: " << intStack.size() << endl;

    intStack.pop();
    intStack.pop();

    intStack.display();

    cout << "\n=== String Stack ===\n";
    DynamicStack<string> stringStack;

    stringStack.push("CS101");
    stringStack.push("Data Structures");
    stringStack.push("C++ Templates");

    stringStack.display();

    cout << "Top: " << stringStack.peek() << endl;

    stringStack.pop();
    stringStack.display();

    return 0;
}

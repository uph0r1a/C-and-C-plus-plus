#include <iostream>
using namespace std;

template <class T>
class StaticStack
{
private:
    static const int MAX = 5;
    T arr[MAX];
    int top;

public:
    StaticStack()
    {
        top = -1;
    }

    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push element\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop\n";
            return;
        }
        cout << arr[top--] << " popped\n";
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T();
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    StaticStack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);
    intStack.push(50);
    intStack.push(60);

    intStack.display();

    cout << "Top element: " << intStack.peek() << endl;
    cout << "Size: " << intStack.size() << endl;

    intStack.pop();
    intStack.pop();
    intStack.display();

    cout << "\n=== String Stack ===\n";
    StaticStack<string> stringStack;

    stringStack.push("Apple");
    stringStack.push("Banana");
    stringStack.push("Cherry");

    stringStack.display();

    cout << "Top element: " << stringStack.peek() << endl;

    stringStack.pop();
    stringStack.display();

    return 0;
}

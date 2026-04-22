#include <iostream>
#include <queue>
using namespace std;

class StringStack
{
private:
    struct Node
    {
        string data;
        Node *next;

        Node(string value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node *top;

public:
    StringStack()
    {
        top = nullptr;
    }

    ~StringStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(const string &value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;

        cout << "\"" << value << "\" pushed onto stack\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty\n";
            return;
        }

        Node *temp = top;
        cout << "\"" << top->data << "\" popped from stack\n";
        top = top->next;
        delete temp;
    }

    string peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return "";
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top -> bottom): ";
        Node *temp = top;

        while (temp != nullptr)
        {
            cout << "\"" << temp->data << "\" ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size()
    {
        int count = 0;
        Node *temp = top;

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
    StringStack stack;

    stack.push("Hello");
    stack.push("Data Structures");
    stack.push("C++ Dynamic Stack");

    cout << "\nCurrent Stack:\n";
    stack.display();

    cout << "\nTop element: \"" << stack.peek() << "\"\n";
    cout << "Size: " << stack.size() << "\n\n";

    stack.pop();
    stack.pop();

    cout << "\nAfter popping two elements:\n";
    stack.display();

    cout << "\nFinal size: " << stack.size() << "\n";
    return 0;
}

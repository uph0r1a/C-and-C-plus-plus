#include <iostream>
#include <string>
using namespace std;

class CharStack
{
private:
    struct Node
    {
        char data;
        Node *next;
    };

    Node *top;

public:
    CharStack()
    {
        top = nullptr;
    }

    ~CharStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(char ch)
    {
        Node *newNode = new Node;
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
            return;

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

bool isBalanced(string str)
{
    CharStack stack;

    for (char ch : str)
    {
        if (ch == '(')
        {
            stack.push(ch);
        }
        else if (ch == ')')
        {
            if (stack.isEmpty())
            {
                return false;
            }
            stack.pop();
        }
    }

    return stack.isEmpty();
}

int main(int argc, char const *argv[])
{
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (isBalanced(input))
    {
        cout << "Parentheses are balanced.\n";
    }
    else
    {
        cout << "Parentheses are NOT balanced.\n";
    }

    return 0;
}
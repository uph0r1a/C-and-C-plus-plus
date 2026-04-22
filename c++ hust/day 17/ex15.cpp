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
            pop();
    }

    void push(char ch)
    {
        Node *newNode = new Node;
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
            return '\0';

        Node *temp = top;
        char value = top->data;
        top = top->next;
        delete temp;

        return value;
    }

    char peek()
    {
        if (isEmpty())
            return '\0';
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

bool isProperlyDelimited(string str)
{
    CharStack stack;

    for (char ch : str)
    {

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']')
        {

            if (stack.isEmpty())
                return false;

            char top = stack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main(int argc, char const *argv[])
{
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (isProperlyDelimited(input))
    {
        cout << "String is properly delimited.\n";
    }
    else
    {
        cout << "String is NOT properly delimited.\n";
    }

    return 0;
}
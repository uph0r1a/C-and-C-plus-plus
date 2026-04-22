#include <iostream>
#include <fstream>
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
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
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
        if (top == nullptr)
            return '\0';

        Node *temp = top;
        char value = top->data;
        top = top->next;
        delete temp;

        return value;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main(int argc, char const *argv[])
{

    CharStack stack;

    string inputFile = "files/input.txt";
    string outputFile = "files/output.txt";

    ifstream fin(inputFile);

    if (!fin)
    {
        cout << "Error opening input file!\n";
        return 1;
    }

    char ch;

    while (fin.get(ch))
    {
        stack.push(ch);
    }

    fin.close();

    ofstream fout(outputFile);

    if (!fout)
    {
        cout << "Error opening output file!\n";
        return 1;
    }

    while (!stack.isEmpty())
    {
        fout.put(stack.pop());
    }

    fout.close();

    cout << "File reversed successfully!\n";

    return 0;
}
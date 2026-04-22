#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

class CharQueue
{
private:
    struct Node
    {
        char data;
        Node *next;
    };

    Node *front;
    Node *rear;

public:
    CharQueue()
    {
        front = rear = nullptr;
    }

    ~CharQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(char ch)
    {
        Node *newNode = new Node;
        newNode->data = ch;
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
    }

    char dequeue()
    {
        if (isEmpty())
            return '\0';

        Node *temp = front;
        char value = front->data;
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
};

int main(int argc, char const *argv[])
{

    string inputFile = "files/input.txt";
    string outputFile = "files/output.txt";

    CharQueue queue;
    char ch;

    ifstream fin(inputFile);
    if (!fin)
    {
        cout << "Error opening input file!\n";
        return 1;
    }

    while (fin.get(ch))
    {
        queue.enqueue(ch);
    }

    fin.close();

    ofstream fout(outputFile);
    if (!fout)
    {
        cout << "Error opening output file!\n";
        return 1;
    }

    while (!queue.isEmpty())
    {
        char c = queue.dequeue();
        fout.put(toupper(c));
    }

    fout.close();

    cout << "File converted to uppercase successfully!\n";

    return 0;
}
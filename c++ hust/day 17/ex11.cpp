#include <iostream>
#include <fstream>
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

    string file1 = "files/input1.txt";
    string file2 = "files/input2.txt";

    ifstream fin1(file1), fin2(file2);

    if (!fin1 || !fin2)
    {
        cout << "Error opening one or both files.\n";
        return 1;
    }

    CharQueue q1, q2;
    char ch;

    while (fin1.get(ch))
    {
        q1.enqueue(ch);
    }

    while (fin2.get(ch))
    {
        q2.enqueue(ch);
    }

    fin1.close();
    fin2.close();

    bool identical = true;
    int position = 1;

    while (!q1.isEmpty() && !q2.isEmpty())
    {
        char c1 = q1.dequeue();
        char c2 = q2.dequeue();

        if (c1 != c2)
        {
            cout << "Files are NOT identical.\n";
            cout << "Mismatch at position " << position
                 << ": '" << c1 << "' != '" << c2 << "'\n";
            identical = false;
            break;
        }

        position++;
    }

    if (identical && (!q1.isEmpty() || !q2.isEmpty()))
    {
        cout << "Files are NOT identical (different lengths).\n";
        identical = false;
    }

    if (identical)
    {
        cout << "Files are identical.\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
    };

    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *nodePtr = head;
        Node *nextNode;

        while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void appendNode(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *nodePtr = head;
            while (nodePtr->next)
            {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newNode;
        }
    }

    void insertNode(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value)
    {
        if (!head)
            return;

        Node *nodePtr = head;
        Node *previousNode = nullptr;

        if (head->value == value)
        {
            head = head->next;
            delete nodePtr;
        }
        else
        {
            while (nodePtr != nullptr && nodePtr->value != value)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            if (nodePtr)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }

    void print() const
    {
        Node *nodePtr = head;

        while (nodePtr)
        {
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    LinkedList list;

    list.appendNode(10);
    list.appendNode(20);
    list.insertNode(5);
    list.deleteNode(20);
    list.print();

    return 0;
}
#include <iostream>
#include <stdexcept>
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

    LinkedList(const LinkedList &other)
    {
        if (!other.head)
        {
            head = nullptr;
            return;
        }

        head = new Node;
        head->value = other.head->value;
        head->next = nullptr;

        Node *nodePtr = head;
        Node *otherPtr = other.head->next;

        while (otherPtr)
        {
            nodePtr->next = new Node;
            nodePtr->next->value = otherPtr->value;
            nodePtr->next->next = nullptr;

            nodePtr = nodePtr->next;
            otherPtr = otherPtr->next;
        }
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

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    int search(int value) const
    {
        Node *nodePtr = head;
        int pos = 0;

        while (nodePtr)
        {
            if (nodePtr->value == value)
            {
                return pos;
            }
            nodePtr = nodePtr->next;
            pos++;
        }

        return -1;
    }

    void insertAtPosition(int value, int pos)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if (pos <= 0 || !head)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *nodePtr = head;
        int index = 0;

        while (nodePtr->next != nullptr && index < pos - 1)
        {
            nodePtr = nodePtr->next;
            index++;
        }

        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }

    void deleteAtPosition(int pos)
    {
        if (!head || pos < 0)
        {
            return;
        }

        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *nodePtr = head;
        int index = 0;

        while (nodePtr->next != nullptr && index < pos - 1)
        {
            nodePtr = nodePtr->next;
            index++;
        }

        if (nodePtr->next != nullptr)
        {
            Node *temp = nodePtr->next;
            nodePtr->next = temp->next;
            delete temp;
        }
    }

    const int &operator[](int index) const
    {
        if (index < 0)
            throw out_of_range("Negative index not allowed");

        Node *nodePtr = head;
        int count = 0;

        while (nodePtr)
        {
            if (count == index)
                return nodePtr->value;

            nodePtr = nodePtr->next;
            count++;
        }

        throw out_of_range("Index out of range");
    }
};

int main(int argc, char const *argv[])
{
    LinkedList list;

    list.appendNode(10);
    list.appendNode(20);
    list.insertNode(5);
    list.deleteNode(20);
    list.insertAtPosition(5, 0);
    list.insertAtPosition(15, 2);
    list.insertAtPosition(40, 10);
    list.deleteAtPosition(0);
    cout << list.search(10) << endl;

    LinkedList copylist(list);

    list.reverse();
    list.print();
    cout << endl;
    cout << list[0];
    cout << list[1];
    copylist.print();

    return 0;
}
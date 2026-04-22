#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
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
            nodePtr = nodePtr->next;

            nodePtr->value = otherPtr->value;
            nodePtr->next = nullptr;

            otherPtr = otherPtr->next;
        }
    }

    ~LinkedList()
    {
        Node *nodePtr = head;
        while (nodePtr)
        {
            Node *nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void appendNode(T value)
    {
        Node *newNode = new Node{value, nullptr};

        if (!head)
        {
            head = newNode;
            return;
        }

        Node *nodePtr = head;
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }

    void insertNode(T value)
    {
        Node *newNode = new Node{value, head};
        head = newNode;
    }

    void deleteNode(T value)
    {
        if (!head)
            return;

        Node *nodePtr = head;
        Node *previous = nullptr;

        if (head->value == value)
        {
            head = head->next;
            delete nodePtr;
            return;
        }

        while (nodePtr && nodePtr->value != value)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
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
        cout << endl;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    int search(T value) const
    {
        Node *nodePtr = head;
        int pos = 0;

        while (nodePtr)
        {
            if (nodePtr->value == value)
                return pos;

            nodePtr = nodePtr->next;
            pos++;
        }

        return -1;
    }

    void insertAtPosition(T value, int pos)
    {
        Node *newNode = new Node{value, nullptr};

        if (pos <= 0 || !head)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *nodePtr = head;
        int index = 0;

        while (nodePtr->next && index < pos - 1)
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
            return;

        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *nodePtr = head;
        int index = 0;

        while (nodePtr->next && index < pos - 1)
        {
            nodePtr = nodePtr->next;
            index++;
        }

        if (nodePtr->next)
        {
            Node *temp = nodePtr->next;
            nodePtr->next = temp->next;
            delete temp;
        }
    }
};

int main(int argc, char const *argv[])
{
    LinkedList<int> list;

    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);

    list.insertAtPosition(5, 0);
    list.insertAtPosition(15, 2);

    list.print();

    list.reverse();
    list.print();

    cout << "Search 20: " << list.search(20) << endl;

    list.deleteAtPosition(1);
    list.print();

    LinkedList<int> copy(list);
    copy.print();

    return 0;
}
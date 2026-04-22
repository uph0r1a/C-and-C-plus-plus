#include <iostream>
using namespace std;

template <typename T>
class ListNode
{
public:
    T value;
    ListNode<T> *next;

    ListNode(T nodeValue)
    {
        value = nodeValue;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
private:
    ListNode<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        ListNode<T> *nodePtr = head;
        ListNode<T> *nextNode;

        while (nodePtr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void appendNode(T newValue)
    {
        ListNode<T> *newNode = new ListNode<T>(newValue);
        ListNode<T> *nodePtr;

        if (!head)
            head = newNode;
        else
        {
            nodePtr = head;

            while (nodePtr->next)
                nodePtr = nodePtr->next;

            nodePtr->next = newNode;
        }
    }
    void insertNode(T newValue)
    {
        ListNode<T> *newNode = new ListNode<T>(newValue);
        ListNode<T> *nodePtr;
        ListNode<T> *previousNode = nullptr;

        if (!head)
        {
            head = newNode;
            return;
        }

        nodePtr = head;

        while (nodePtr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (!previousNode)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    void deleteNode(T searchValue)
    {
        if (!head)
            return;

        ListNode<T> *nodePtr;
        ListNode<T> *previousNode;

        if (head->value == searchValue)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        else
        {
            nodePtr = head;

            while (nodePtr && nodePtr->value != searchValue)
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
    void displayList() const
    {
        ListNode<T> *nodePtr = head;

        while (nodePtr)
        {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
    }

    int search(T value) const
    {
        ListNode<T> *nodePtr = head;
        int position = 1;

        while (nodePtr)
        {
            if (nodePtr->value == value)
                return position;

            nodePtr = nodePtr->next;
            position++;
        }

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList<int> list;

    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);
    list.appendNode(40);

    cout << "List:\n";
    list.displayList();

    cout << "\nSearch results:\n";
    cout << "Search 20: " << list.search(20) << endl;
    cout << "Search 100: " << list.search(100) << endl;

    return 0;
}
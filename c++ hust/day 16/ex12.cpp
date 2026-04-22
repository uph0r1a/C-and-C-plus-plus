#include <iostream>
using namespace std;

class NumberList
{
private:
    struct ListNode
    {
        double value;
        ListNode *next;
    };

    ListNode *head;

public:
    NumberList()
    {
        head = nullptr;
    }

    ~NumberList()
    {
        ListNode *nodePtr = head;
        ListNode *nextNode;

        while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void appendNode(double num)
    {
        ListNode *newNode = new ListNode;
        newNode->value = num;
        newNode->next = nullptr;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            ListNode *nodePtr = head;

            while (nodePtr->next)
                nodePtr = nodePtr->next;

            nodePtr->next = newNode;
        }
    }

    void insertNode(double num)
    {
        ListNode *newNode = new ListNode;
        newNode->value = num;

        ListNode *nodePtr;
        ListNode *previousNode = nullptr;

        if (!head)
        {
            head = newNode;
            newNode->next = nullptr;
            return;
        }

        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value < num)
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

    void deleteNode(double num)
    {
        if (!head)
            return;

        ListNode *nodePtr;
        ListNode *previousNode;

        if (head->value == num)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        else
        {
            nodePtr = head;

            while (nodePtr != nullptr && nodePtr->value != num)
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
        ListNode *nodePtr = head;

        while (nodePtr)
        {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
    }

    void mergeArray(double arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            insertNode(arr[i]);
        }
    }
};

int main(int argc, char const *argv[])
{
    NumberList list;

    double arr[] = {5.5, 2.2, 9.9, 1.1, 7.7};
    int size = 5;

    list.mergeArray(arr, size);

    cout << "Merged Sorted List:\n";
    list.displayList();

    return 0;
    return 0;
}

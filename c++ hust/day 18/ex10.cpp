#include <iostream>
#include <limits>
using namespace std;

class NumberList
{
private:
    struct ListNode
    {
        double value;
        struct ListNode *next;
    };

    ListNode *head;

    int countNodes(ListNode *nodePtr) const
    {
        if (nodePtr != nullptr)
            return 1 + countNodes(nodePtr->next);
        else
            return 0;
    }

    void showReverse(ListNode *nodePtr) const
    {
        if (nodePtr != nullptr)
        {
            showReverse(nodePtr->next);
            cout << nodePtr->value << " ";
        }
    }

    double maxNodeHelper(ListNode *nodePtr) const
    {
        if (nodePtr == nullptr)
            return -numeric_limits<double>::infinity();

        double maxInRest = maxNodeHelper(nodePtr->next);

        return (nodePtr->value > maxInRest) ? nodePtr->value : maxInRest;
    }

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
            head = newNode;
        else
        {
            ListNode *nodePtr = head;

            while (nodePtr->next)
                nodePtr = nodePtr->next;

            nodePtr->next = newNode;
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

    int numNodes() const
    {
        return countNodes(head);
    }

    void displayBackwards() const
    {
        showReverse(head);
    }

    double maxNode() const
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return -numeric_limits<double>::infinity();
        }

        return maxNodeHelper(head);
    }
};

int main()
{
    NumberList list;

    list.appendNode(12.5);
    list.appendNode(3.8);
    list.appendNode(99.2);
    list.appendNode(45.6);
    list.appendNode(7.1);

    cout << "List contents:\n";
    list.displayList();

    cout << "\nNumber of nodes: " << list.numNodes() << endl;

    cout << "\nList in reverse:\n";
    list.displayBackwards();
    cout << endl;

    cout << "\nMaximum value in list: " << list.maxNode() << endl;

    return 0;
}
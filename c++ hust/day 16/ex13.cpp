#include <iostream>
#include <fstream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        double value;
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
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(double value)
    {
        Node *newNode = new Node{value, nullptr};

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next)
                ptr = ptr->next;

            ptr->next = newNode;
        }
    }

    void saveToFile(const string &filename)
    {
        ofstream file(filename);

        Node *ptr = head;
        while (ptr)
        {
            file << ptr->value << endl;
            ptr = ptr->next;
        }

        file.close();
    }

    void loadFromFile(const string &filename)
    {
        ifstream file(filename);

        double value;
        while (file >> value)
        {
            append(value);
        }

        file.close();
    }

    void display() const
    {
        Node *ptr = head;
        int month = 1;

        while (ptr)
        {
            cout << "Month " << month << ": " << ptr->value << endl;
            ptr = ptr->next;
            month++;
        }
    }

    void clear()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(int argc, char const *argv[])
{
    LinkedList rainfall;

    int months;
    cout << "How many months of rainfall data? ";
    cin >> months;

    // INPUT PHASE
    for (int i = 0; i < months; i++)
    {
        double value;

        cout << "Enter rainfall month " << i + 1 << ": ";

        while (true)
        {
            cin >> value;
            if (value >= 0)
                break;

            cout << "Cannot be negative. Re-enter: ";
        }

        rainfall.append(value);
    }

    rainfall.saveToFile("files/rainfall.txt");
    cout << "\nData saved to files/rainfall.txt\n";

    rainfall.clear();

    rainfall.loadFromFile("files/rainfall.txt");

    cout << "\nData loaded from file:\n";
    rainfall.display();

    return 0;
}
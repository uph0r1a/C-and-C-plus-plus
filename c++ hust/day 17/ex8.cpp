#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <class T>
class DynamicStack
{
protected:
    Node<T> *top;

public:
    DynamicStack()
    {
        top = nullptr;
    }

    ~DynamicStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    T getTopValue()
    {
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int size()
    {
        int count = 0;
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

template <class T>
class MathStack : public DynamicStack<T>
{
public:
    void add()
    {
        T a, b;
        a = this->getTopValue();
        this->pop();
        b = this->getTopValue();
        this->pop();
        this->push(a + b);
    }

    void sub()
    {
        T a, b;
        a = this->getTopValue();
        this->pop();
        b = this->getTopValue();
        this->pop();
        this->push(b - a);
    }

    void mult()
    {
        T a, b;
        a = this->getTopValue();
        this->pop();
        b = this->getTopValue();
        this->pop();
        this->push(a * b);
    }

    void div()
    {
        T a, b;
        a = this->getTopValue();
        this->pop();
        b = this->getTopValue();
        this->pop();

        if (a == 0)
        {
            cout << "Division by zero error\n";
            return;
        }

        this->push(b / a);
    }

    void addAll()
    {
        T sum = 0;
        while (!this->isEmpty())
        {
            sum += this->getTopValue();
            this->pop();
        }
        this->push(sum);
    }

    void multAll()
    {
        T product = 1;

        if (this->isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        while (!this->isEmpty())
        {
            product *= this->getTopValue();
            this->pop();
        }

        this->push(product);
    }
};

int main(int argc, char const *argv[])
{
    MathStack<int> s;

    s.push(10);
    s.push(5);
    s.push(2);

    s.mult();
    s.push(4);
    s.add();

    cout << "\nAfter operations, top result = " << s.getTopValue() << endl;

    s.addAll();
    cout << "Final result = " << s.getTopValue() << endl;

    return 0;
}

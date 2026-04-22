#include <iostream>
using namespace std;

class IntStack
{
private:
    int *stackArray;
    int stackSize;
    int top;

public:
    IntStack(int size)
    {
        stackSize = size;
        stackArray = new int[stackSize];
        top = -1;
    }

    ~IntStack()
    {
        delete[] stackArray;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        stackArray[++top] = value;
    }

    void pop(int &value)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        value = stackArray[top--];
    }

    bool isFull() const
    {
        return top == stackSize - 1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }
};

class MathStack : public IntStack
{
public:
    MathStack(int s) : IntStack(s) {}

    void add()
    {
        int num, sum;
        pop(sum);
        pop(num);
        sum += num;
        push(sum);
    }

    void sub()
    {
        int num, diff;
        pop(diff);
        pop(num);
        diff -= num;
        push(diff);
    }

    void mult()
    {
        int a, b;
        pop(a);
        pop(b);
        push(a * b);
    }

    void div()
    {
        int a, b;
        pop(a);
        pop(b);

        if (a == 0)
        {
            cout << "Division by zero error\n";
            return;
        }

        push(b / a);
    }

    void addAll()
    {
        int sum = 0;
        int value;

        while (!isEmpty())
        {
            pop(value);
            sum += value;
        }

        push(sum);
    }

    void multAll()
    {
        int product = 1;
        int value;

        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        while (!isEmpty())
        {
            pop(value);
            product *= value;
        }

        push(product);
    }
};

int main(int argc, char const *argv[])
{
    MathStack stack(10);

    stack.push(10);
    stack.push(5);
    stack.push(2);
    stack.push(3);
    stack.mult();
    stack.add();
    stack.push(4);
    stack.push(2);
    stack.div();
    stack.addAll();
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.multAll();

    return 0;
}

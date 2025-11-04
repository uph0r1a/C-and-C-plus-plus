#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float length1, length2, width1, width2;
    cout << "Enter the length of rectangle 1: ";
    cin >> length1;
    cout << "Enter the length of rectangle 2: ";
    cin >> length2;
    cout << "Enter the width of rectangle 1: ";
    cin >> width1;
    cout << "Enter the width of rectangle 2: ";
    cin >> width2;

    if (length1 * width1 > length2 * width2)
    {
        cout << "Rectangle 1 has the greater area";
    }
    else if (length1 * width1 == length2 * width2)
    {
        cout << "The areas of the 2 rectangles are the same";
    }
    else
    {
        cout << "Rectangle 2 has the greater area";
    }

    return 0;
}

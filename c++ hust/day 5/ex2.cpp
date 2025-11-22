#include <iostream>
using namespace std;

double getLength(double length)
{
    cout << "Enter the rectangle's length: ";
    cin >> length;
    return length;
}

double getWidth(double width)
{
    cout << "Enter the rectangle's width: ";
    cin >> width;
    return width;
}

double getArea(double length, double width)
{
    return width * length;
}

void displayData(double length, double area, double width)
{
    length = getLength(length);
    width = getWidth(width);
    area = getArea(length, width);
    cout << "Length: " << length << "\nWidth: " << width << "\nArea: " << area;
}

int main(int argc, char const *argv[])
{
    double length, width, area;

    displayData(length, width, area);
    return 0;
}

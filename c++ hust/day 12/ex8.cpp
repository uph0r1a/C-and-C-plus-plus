#include <iostream>
using namespace std;

class Circle
{
public:
    Circle()
    {
        radius = 0;
    }

    Circle(double r)
    {
        radius = r;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    double getRadius() const
    {
        return radius;
    }

    double getArea() const
    {
        return pi * radius * radius;
    }

    double getDiameter() const
    {
        return radius * 2;
    }

    double getCircumference() const
    {
        return 2 * pi * radius;
    }

private:
    double radius;
    const double pi = 3.14159;
};

int main(int argc, char const *argv[])
{
    double radius;

    cout << "Enter a radius: ";
    cin >> radius;

    Circle circle(radius);

    cout << "Radius: " << circle.getRadius() << endl
         << "Area: " << circle.getArea() << endl
         << "Diameter: " << circle.getDiameter() << endl
         << "Circumference: " << circle.getCircumference() << endl;

    return 0;
}

#include <iostream>
using namespace std;

class BasicShape
{
protected:
    double area;

public:
    double getArea() const
    {
        return area;
    }

    virtual void calcArea() = 0;
};

class Circle : public BasicShape
{
private:
    long int centerX, centerY;
    double radius;

public:
    Circle(long int x, long int y, double r)
        : centerX(x),
          centerY(y),
          radius(r)
    {
        calcArea();
    }

    long int getCenterX() const
    {
        return centerX;
    }

    long int getCenterY() const
    {
        return centerY;
    }

    void calcArea() override
    {
        area = 3.14159 * radius * radius;
    }
};

class Rectangle : public BasicShape
{
private:
    long int width, length;

public:
    Rectangle(long int w, long int l)
        : width(w),
          length(l)
    {
        calcArea();
    }

    long int getWidth() const
    {
        return width;
    }

    long int getLength() const
    {
        return length;
    }

    void calcArea() override
    {
        area = length * width;
    }
};

int main(int argc, char const *argv[])
{
    Circle c(3, 4, 5);
    Rectangle r(3, 5);

    cout << "Circle area: " << c.getArea() << endl
         << "Rectangle area: " << r.getArea() << endl;

    return 0;
}

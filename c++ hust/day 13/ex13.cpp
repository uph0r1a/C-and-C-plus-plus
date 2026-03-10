#include <iostream>
#include <cstdlib>
using namespace std;

class FeetInches
{
private:
    int feet;
    int inches;
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1);
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    void setFeet(int f)
    {
        feet = f;
    }

    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    int getFeet() const
    {
        return feet;
    }

    int getInches() const
    {
        return inches;
    }

    int toInches() const
    {
        return feet * 12 + inches;
    }

    FeetInches operator+(const FeetInches &right)
    {
        FeetInches temp;
        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();
        return temp;
    }

    FeetInches operator-(const FeetInches &right)
    {
        FeetInches temp;
        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();
        return temp;
    }

    FeetInches &operator++()
    {
        ++inches;
        simplify();
        return *this;
    }

    FeetInches operator++(int)
    {
        FeetInches temp(feet, inches);
        inches++;
        simplify();
        return temp;
    }

    bool operator>(const FeetInches &right) const
    {
        if (feet > right.feet)
            return true;
        else if (feet == right.feet && inches > right.inches)
            return true;
        else
            return false;
    }

    bool operator<(const FeetInches &right) const
    {
        if (feet < right.feet)
            return true;
        else if (feet == right.feet && inches < right.inches)
            return true;
        else
            return false;
    }

    bool operator==(const FeetInches &right) const
    {
        if (feet == right.feet && inches == right.inches)
            return true;
        else
            return false;
    }

    operator double() const
    {
        double temp = feet;
        temp += (inches / 12.0);
        return temp;
    }

    operator int() const
    {
        return feet;
    }

    friend ostream &operator<<(ostream &strm, const FeetInches &obj)
    {
        strm << obj.feet << " feet, " << obj.inches << " inches";
        return strm;
    }

    friend istream &operator>>(istream &strm, FeetInches &obj)
    {
        cout << "Feet: ";
        strm >> obj.feet;

        cout << "Inches: ";
        strm >> obj.inches;

        obj.simplify();
        return strm;
    }

    bool operator<=(const FeetInches &right) const
    {
        return (*this < right) || (*this == right);
    }

    bool operator>=(const FeetInches &right) const
    {
        return (*this > right) || (*this == right);
    }

    bool operator!=(const FeetInches &right) const
    {
        return !(*this == right);
    }

    FeetInches(const FeetInches &obj)
    {
        feet = obj.feet;
        inches = obj.inches;
    }

    FeetInches multiply(const FeetInches &right) const
    {
        FeetInches temp;
        temp.feet = feet * right.feet;
        temp.inches = inches * right.inches;
        temp.simplify();
        return temp;
    }
};

class RoomDimension
{
private:
    FeetInches length, width;

public:
    RoomDimension(FeetInches w = 0, FeetInches l = 0)
        : width(w),
          length(l) {}

    double getAreaSqFt() const
    {
        return (double)width * (double)length;
    }

    FeetInches getArea() const
    {
        return width.multiply(length);
    }
};

class RoomCarpet
{
private:
    RoomDimension room;
    float costPerSqft;

public:
    RoomCarpet(RoomDimension r, float cost = 0)
        : room(r),
          costPerSqft(cost) {}

    double getTotalCost() const
    {
        return room.getAreaSqFt() * costPerSqft;
    }
};

int main(int argc, char const *argv[])
{
    FeetInches width, length;
    float cost;

    cout << "Enter width: \n";
    cin >> width;

    cout << "Enter length: \n";
    cin >> length;

    cout << "Enter cost per square feet: ";
    cin >> cost;

    RoomDimension room(width, length);
    RoomCarpet carpet(room, cost);

    cout << "Total cost: " << carpet.getTotalCost() << endl;

    return 0;
}
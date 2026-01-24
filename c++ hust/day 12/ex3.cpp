#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    Car(int yModel, string m)
    {
        yearModel = yModel;
        make = m;
        speed = 0;
    }

    int getYearModel() const
    {
        return yearModel;
    }

    int getSpeed() const
    {
        return speed;
    }

    string getMake() const
    {
        return make;
    }

    void accelerate()
    {
        speed += 5;
    }

    int brake()
    {
        speed <= 0 ? speed = 0 : speed -= 5;
    }

private:
    int yearModel, speed;
    string make;
};

int main(int argc, char const *argv[])
{
    Car car(2025, "Ferrari");

    cout << "The make of the car: " << car.getMake() << endl
         << "Year's model: " << car.getYearModel() << endl
         << "Speed: " << car.getSpeed() << endl;

    for (int i = 0; i < 5; i++)
    {
        car.accelerate();
    }

    cout << "Speed: " << car.getSpeed() << endl;

    for (int i = 0; i < 6; i++)
    {
        car.brake();
    }

    cout << "Speed: " << car.getSpeed() << endl;
    return 0;
}

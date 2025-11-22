#include <iostream>
#include <cmath>
using namespace std;

float kineticEnergy(float mass, float velocity)
{
    return 0.5 * mass * pow(velocity, 2);
}

int main(int argc, char const *argv[])
{
    float kinetic_energy, mass, velocity;

    cout << "Enter the object's mass (in kilograms): ";
    cin >> mass;

    cout << "Enter the velocity (in meters per second): ";
    cin >> velocity;

    kinetic_energy = kineticEnergy(mass, velocity);

    cout << "Kinetic energy: " << kinetic_energy;

    return 0;
}

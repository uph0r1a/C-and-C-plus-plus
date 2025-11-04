#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float mass, weight;
    cout << "Enter an object's mass: ";
    cin >> mass;
    weight = mass * 9.8;
    cout << "Weight: " << weight;
    if (weight > 1000)
    {
        cout << "It is too heavy";
    }
    else if (weight < 10)
    {
        cout << "The object is too light";
    }

    return 0;
}

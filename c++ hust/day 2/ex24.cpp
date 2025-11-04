#include <string>
#include <iostream>
using namespace std;

int main()
{
    string name, city, college, profession, type_of_animal, pet_name;
    int age;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter the name of a city: ";
    getline(cin, city);

    cout << "Enter the name of a college: ";
    getline(cin, college);

    cout << "Enter a profession: ";
    getline(cin, profession);

    cout << "Enter a type of animal: ";
    getline(cin, type_of_animal);

    cout << "Enter a pet's name: ";
    getline(cin, pet_name);

    cout << "\nThere once was a person named " << name
         << " who lived in " << city << ". At the age of "
         << age << ", " << name << " went to college at "
         << college << ". " << name << " graduated and went to work as a "
         << profession << ". Then, " << name << " adopted a(n) "
         << type_of_animal << " named " << pet_name
         << ". They both lived happily ever after!" << endl;

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    string filename;
    int count = 0;
    double sum = 0.0;
    double number;

    ifstream inFile("Random.txt");

    if (!inFile)
    {
        cerr << "Could not open file " << endl;
        return 1;
    }

    while (inFile >> number)
    {
        sum += number;
        count++;
    }

    inFile.close();

    if (count == 0)
    {
        cout << "No numbers found in the file." << endl;
    }
    else
    {
        double average = sum / count;

        cout << "Number of numbers: " << count << endl;
        cout << "Sum of numbers: " << sum << endl;
        cout << "Average of numbers: " << average << endl;
    }

    return 0;
}

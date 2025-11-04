#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    string fileName = "D:\\coding\\c and c++\\at home c and c++\\a.txt";
    string targetWord = "mot";

    ifstream inputFile(fileName);

    string word;
    int wordCount = 0;

    while (inputFile >> word) {
        if (toLowerCase(word) == toLowerCase(targetWord)) {
            wordCount++;
            cout << "\033[1;31m" << word << "\033[0m ";
        }
        else {
            cout << word << " ";
        }
    }

    cout << "\nThe word \"" << targetWord << "\" appeared " << wordCount << " times." << endl;
}

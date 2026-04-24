#include <iostream>
using namespace std;

bool isMember(int arr[], int value) {
    if (arr[0] == '\0') {
        return false;
    }

    if (arr[0] == value) {
        return true;
    }

    if (arr[1] == '\0') {
        return (arr[0] == value);
    }

    return isMember(arr + 1, value);
}

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int value;
    cout << "Enter value to search: ";
    cin >> value;

    if (isMember(arr, value)) {
        cout << value << " is found in the array." << endl;
    } else {
        cout << value << " is NOT found in the array." << endl;
    }

    return 0;
}
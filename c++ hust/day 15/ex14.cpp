#include <iostream>
#include <vector>
using namespace std;

vector<int> Sort(vector<int> arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

float Average(vector<int> arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<float>(sum) / static_cast<float>(size);
}

int main(int argc, char const *argv[])
{
    char choice;
    vector<int> arr;

    while (1)
    {
        cout << "Enter score number: ";
        while (1)
        {
            int tmp;
            cin >> tmp;
            if (tmp >= 0)
            {
                arr.push_back(tmp);
                break;
            }
            cout << "Test score cannot be negative\nRe-enter score number: ";
        }

        while (1)
        {
            cout << "Do you want to continue(Y/N)?";
            cin >> choice;
            if (tolower(choice) == 'y' || tolower(choice) == 'n')
            {
                break;
            }
            cout << "Invalid choice\n";
        }

        if (tolower(choice) == 'n')
        {
            break;
        }
    }

    int size = arr.size();

    arr = Sort(arr, size);
    float average = Average(arr, size);

    cout << "Sort score array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nAverage score: " << average << endl;

    return 0;
}

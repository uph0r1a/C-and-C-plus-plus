#include <iostream>
using namespace std;

void Monkey()
{
    float food[3][5], average_per_day, min, max, sum = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Monkey " << i + 1 << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter the number of food in pound for day " << j + 1 << ": ";
            while (1)
            {
                cin >> food[i][j];
                if (food[i][j] >= 0)
                {
                    if (i == 0 && j == 0)
                    {
                        min = food[i][j];
                        max = food[i][j];
                    }
                    break;
                }
                cout << "Numbers for pounds of food eaten cannot be negative\nRe-Enter the number of food in pound for day " << j + 1 << ": ";
            }

            if (food[i][j] < min)
            {
                min = food[i][j];
            }
            if (food[i][j] > max)
            {
                max = food[i][j];
            }

            sum += food[i][j];
        }
    }

    average_per_day = sum / 5;

    cout << "Average amount of food eaten per day by the whole family of monkeys: " << average_per_day << endl
         << "The least amount of food eaten during the week by any one monkey: " << min << endl
         << "The greatest amount of food eaten during the week by any one monkey: " << max;
}

int main(int argc, char const *argv[])
{
    Monkey();
    return 0;
}

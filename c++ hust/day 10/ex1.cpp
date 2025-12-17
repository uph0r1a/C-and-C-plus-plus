#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    string title, director;
    int yearRealased, runningTime;
} MovieData;

void Display(MovieData movie[2])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Movie " << i + 1 << ": " << endl
             << "Title: " << movie[i].title << endl
             << "Director: " << movie[i].director << endl
             << "Year Released: " << movie[i].yearRealased << endl
             << "Running Time (in minutes): " << movie[i].runningTime << endl;
    }
}

int main(int argc, char const *argv[])
{
    MovieData movie[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "Movie " << i + 1 << ": " << endl;
        cout << "Title: ";

        while (1)
        {
            getline(cin, movie[i].title);
            if (!movie[i].title.empty())
            {
                break;
            }
            cout << "The title must not be empty\nRe-enter the title: ";
        }
        cout << "Director: ";
        while (1)
        {
            getline(cin, movie[i].director);
            if (!movie[i].director.empty())
            {
                break;
            }
            cout << "The director must not be empty\nRe-enter the director: ";
        }

        cout << "Year Released: ";
        while (1)
        {
            cin >> movie[i].yearRealased;
            if (movie[i].runningTime >= 1500 && movie[i].runningTime <= 2100)
            {
                break;
            }
            cout << "Year released must be around 1500 and 2100\nRe-enter year released: ";
        }

        cout << "Running Time (in minutes): ";
        while (1)
        {
            cin >> movie[i].runningTime;
            if (movie[i].runningTime > 0)
            {
                break;
            }
            cout << "Running time cannot be negative\nRe-enter running Time (in minutes): ";
        }

        cin.ignore();
    }

    Display(movie);
    return 0;
}

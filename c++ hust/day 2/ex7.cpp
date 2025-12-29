#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string movie_name;
    int number_of_adult, number_of_child;

    cout << "Enter the name of the movie: ";
    getline(cin, movie_name);
    cout << "How many adult tickets: ";
    cin >> number_of_adult;
    cout << "How many child tickets: ";
    cin >> number_of_child;

    cout << "Movie Name: " << setw(35) << movie_name << "\n"
         << "Adult Tickets Sold: " << setw(20) << number_of_adult << "\n"
         << "Child Tickets Sold: " << setw(20) << number_of_child << "\n"
         << "Gross Box Office Profit: " << setw(11) << "$" << fixed << setprecision(2) << (float)(number_of_adult * 10 + number_of_child * 6) << "\n"
         << "Net Box Office Profit: " << setw(14) << "$ " << fixed << setprecision(2) << (float)((number_of_adult * 10 + number_of_child * 6) * 0.2) << "\n"
         << "Amount Paid to Distributor: " << setw(8) << "$" << fixed << setprecision(2) << (float)((number_of_adult * 10 + number_of_child * 6) - ((number_of_adult * 10 + number_of_child * 6) * 0.2)) << endl;
    return 0;
}
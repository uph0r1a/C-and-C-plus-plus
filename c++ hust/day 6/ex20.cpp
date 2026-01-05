#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Seatprice(float seatPrice[15])
{
    int choice;
    bool valid = false;
    string filename;

    cout << "Do you want to:\n"
         << "(1) Enter the seat price\n"
         << "(2) Read from a file\n"
         << "Enter choice: ";

    while (!valid)
    {
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < 15; i++)
            {
                cout << "Enter the seat price for row " << i + 1 << ": ";
                cin >> seatPrice[i];
            }
            valid = true;
        }
        else if (choice == 2)
        {
            cout << "Enter the file name: ";
            cin >> filename;

            ifstream f("files/" + filename);
            if (!f)
            {
                cout << "Cannot open file\n";
                return;
            }

            for (int i = 0; i < 15; i++)
            {
                if (!(f >> seatPrice[i]))
                {
                    cout << "Invalid file format\n";
                    return;
                }
            }

            f.close();
            valid = true;
        }
        else
        {
            cout << "Invalid choice. Re-enter choice: ";
        }
    }
}

void Ticket(string seatingChart[15][30], float seatPrice[15], int &ticketSale)
{
    ifstream f("files/seatingChart.txt");
    if (!f)
    {
        cout << "Cannot open seating chart file\n";
        return;
    }

    string line;
    for (int i = 0; i < 15; i++)
    {
        getline(f, line);
        if (line.length() < 30)
        {
            cout << "Invalid seating chart format\n";
            return;
        }

        for (int j = 0; j < 30; j++)
        {
            seatingChart[i][j] = string(1, line[j]);
        }
    }
    f.close();

    int choice = 1;
    int row, seat;

    while (choice == 1)
    {
        system("clear");
        cout << "\n\t123456789012345678901234567890\n";
        for (int i = 0; i < 15; i++)
        {
            cout << "Row " << i + 1 << "\t";
            for (int j = 0; j < 30; j++)
                cout << seatingChart[i][j];
            cout << endl;
        }

        while (true)
        {
            cout << "Enter row (1-15): ";
            cin >> row;
            cout << "Enter seat (1-30): ";
            cin >> seat;

            if (row < 1 || row > 15 || seat < 1 || seat > 30)
            {
                cout << "Invalid row or seat\n";
                continue;
            }

            if (seatingChart[row - 1][seat - 1] == "#")
            {
                seatingChart[row - 1][seat - 1] = "*";
                ticketSale++;
                break;
            }
            else
            {
                cout << "Seat already taken\n";
            }
        }

        cout << "Do you want to continue?\n(1) Yes\n(0) No\n";
        cin >> choice;
    }
}

void Summary(string seatingChart[15][30], int ticketSale)
{
    int totalAvailable = 0;

    cout << "\nSeats sold: " << ticketSale << endl;
    cout << "Seats available per row:\n";

    for (int i = 0; i < 15; i++)
    {
        int availablePerRow = 0;
        for (int j = 0; j < 30; j++)
        {
            if (seatingChart[i][j] == "#")
                availablePerRow++;
        }
        cout << "Row " << i + 1 << ": " << availablePerRow << endl;
        totalAvailable += availablePerRow;
    }

    cout << "Total seats available: " << totalAvailable << endl;
}

int main(int argc, char const *argv[])
{
    int ticketSale = 0;
    float seatPrice[15];
    string seatingChart[15][30];

    Seatprice(seatPrice);
    Ticket(seatingChart, seatPrice, ticketSale);
    Summary(seatingChart, ticketSale);

    return 0;
}

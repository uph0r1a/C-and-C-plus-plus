#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void Seatprice(float seatPrice[15])
{
    int choice, flag = 1;
    string filename;
    cout << "Do you want to: " << endl
         << "(1)Enter the seat price " << endl
         << "(2)Read from a file" << endl
         << "Enter choice: ";

    do
    {
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < 15; i++)
            {
                cout << "Enter the seat price for row " << i + 1 << ": ";
                cin >> seatPrice[i];
            }
            flag = 0;
        }

        else if (choice == 2)
        {
            cout << "Enter the file name: ";
            cin >> filename;

            ifstream f(filename);

            if (!f)
            {
                cout << "Cannot open file" << endl;
                return;
            }

            for (int i = 0; i < 15; i++)
            {
                f >> seatPrice[i];
            }

            f.close();
        }
        else
        {
            cout << "Invalid choice" << endl
                 << "Re-enter the choice: ";
        }

    } while (flag);
}

void Ticket(string seatingChart[15][30], float seatPrice[15], int &ticketSale)
{
    int choice, row, seat;
    ifstream f("seatingChart.txt");
    if (!f)
    {
        cout << "Cannot open file";
        return;
    }

    string line;
    for (int i = 0; i < 15; i++)
    {
        getline(f, line);
        for (int j = 0; j < 30; j++)
        {
            seatingChart[i][j] = string(1, line[j]);
        }
    }

    do
    {
        system("clear");
        cout << "\t123456789012345678901234567890" << endl;

        for (int i = 0; i < 15; i++)
        {
            cout << "Row " << i + 1 << "\t";
            for (int j = 0; j < 30; j++)
            {
                cout << seatingChart[i][j];
            }
            cout << endl;
        }

        cout << "Input the row and seat: " << endl;

        while (1)
        {
            cout << "Enter the row(1-15): ";
            while (1)
            {
                cin >> row;
                if (row >= 1 && row <= 15)
                {
                    break;
                }
                cout << "Invalid row\nRe-enter the row(1-15): ";
            }

            cout << "Enter the seat(1-30): ";
            while (1)
            {
                cin >> seat;
                if (seat >= 1 && seat <= 30)
                {
                    break;
                }
                cout << "Invalid seat\nRe-enter the seat(1-30): ";
            }

            if (seatingChart[row - 1][seat - 1] == "#")
            {
                ticketSale++;
                seatingChart[row - 1][seat - 1] = "*";
                break;
            }
            cout << "Seat taken\nRe-enter row and seat: ";
        }
        cout << "Do you want to continue: " << endl
             << "(1)Yes" << endl
             << "(0)No" << endl;

        while (1)
        {
            cin >> choice;
            if (choice == 1 || choice == 0)
            {
                break;
            }
            cout << "Invalid choice\nRe-enter option: ";
        }

    } while (choice);
}

void Summary(string seatingChart[15][30], int ticketSale)
{
    int availablePerRow, totalAvailable = 0;
    cout << "Seats have been sold: " << ticketSale << endl
         << "Seats available per row: " << endl;

    for (int i = 0; i < 15; i++)
    {
        availablePerRow = 0;
        cout << "Row " << i << "\t";
        for (int j = 0; j < 30; j++)
        {
            if (seatingChart[i][j] == "#")
            {
                availablePerRow++;
            }
        }
        cout << availablePerRow;
        totalAvailable += availablePerRow;
        cout << endl;
    }

    cout << "Seats available in the entire auditorium: " << totalAvailable << endl;
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

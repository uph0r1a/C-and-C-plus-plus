#include <iostream>
#include <cstring>
using namespace std;

void Tictactoe()
{
    char board[3][3];
    int isOver = 0;
    memset(board, ' ', sizeof(board));

    do
    {
        int full = true;
        for (int i = 0; i < 3 && !full; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[3][3] == ' ')
                {
                    full = false;
                }
            }
        }

        if (full)
        {
            isOver = 1;
            cout << "Draw" << endl;
        }

        int row = 0, column = 0;
        cout << "-------" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "|" << board[i][j];
            }
            cout << "|" << endl
                 << "-------" << endl;
        }

        cout << "Player 1: " << endl;
        cout << "Enter the row: ";
        while (1)
        {
            cin >> row;
            if (row <= 3 && row >= 1)
            {
                break;
            }
            cout << "Invalid position\nRe-enter the row: ";
        }

        cout << "Enter the column: ";
        while (1)
        {
            cin >> column;
            if (column <= 3 && column >= 1)
            {
                break;
            }
            cout << "Invalid position\nRe-enter the column: ";
        }

        board[row - 1][column - 1] = 'X';

        cout << "Player 2: " << endl;
        cout << "Enter the row: ";
        while (1)
        {
            cin >> row;
            if (row <= 3 && row >= 1)
            {
                break;
            }
            cout << "Invalid position\nRe-enter the row: ";
        }

        cout << "Enter the column: ";
        while (1)
        {
            cin >> column;
            if (column <= 3 && column >= 1)
            {
                break;
            }
            cout << "Invalid position\nRe-enter the column: ";
        }

        board[row - 1][column - 1] = 'O';

        bool flag = false;
        char winner;
        for (int i = 0; i < 3 && !flag; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][0] != board[i][j])
                {
                    break;
                }
                isOver = 1;
                flag = true;
                winner = board[i][0];
            }
        }

        cout << (isOver == 1 ? (winner == 'X' ? "Player 1 win" : "Player 2 win") : "") << endl;

        flag = false;
        for (int j = 0; j < 3 && !flag; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[0][j] != board[i][j])
                {
                    break;
                }
                isOver = 1;
                flag = true;
                winner = board[0][j];
            }
        }

        cout << (isOver == 1 ? (winner == 'X' ? "Player 1 win" : "Player 2 win") : "") << endl;

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            isOver = 1;
            cout<<(board[0][0] == 'X' ? "Player 1 win" : "Player 2 win")<<endl;
        }

        if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        {
            isOver = 1;
            cout<<(board[0][0] == 'X' ? "Player 1 win" : "Player 2 win")<<endl;
        }

    } while (isOver = 0);
}

int main(int argc, char const *argv[])
{
    Tictactoe();
    return 0;
}

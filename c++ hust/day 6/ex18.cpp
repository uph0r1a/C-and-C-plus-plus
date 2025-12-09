#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void renderTable(char board[3][3])
{
    cout << "-------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "-------" << endl;
}

bool checkWinRow(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        char temp = board[i][0];

        if (temp == ' ')
            continue;

        int count = 1;

        for (int j = 1; j < 3; j++)
        {
            if (board[i][j] != temp)
            {
                count = 0;
                break;
            }
            count++;
        }

        if (count == 3)
            return true;
    }

    return false;
}

bool checkWinColumn(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        char temp = board[0][i];
        if (temp == ' ')
            continue;

        bool win = true;

        for (int j = 1; j < 3; j++)
        {
            if (board[j][i] != temp)
            {
                win = false;
                break;
            }
        }

        if (win)
            return true;
    }
    return false;
}

bool checkDiagonalWin(char board[3][3])
{
    if (board[1][1] != ' ' && ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])))
    {
        return true;
    }
    return false;
}

bool isEmpty(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

void Pvp(char board[3][3])
{
    do
    {
        renderTable(board);
        int row, column;
        cout << "Player 1: " << endl;
        while (1)
        {
            cout << "Enter the row(1-3): ";
            while (1)
            {
                cin >> row;
                if (row >= 1 && row <= 3)
                {
                    break;
                }
                cout << "Invalid move\nRe-enter the row: ";
            }
            cout << "Enter the column(1-3): ";
            while (1)
            {
                cin >> column;
                if (column >= 1 && column <= 3)
                {
                    break;
                }
                cout << "Invalid move\nRe-enter the column: ";
            }
            if (board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = 'X';
                break;
            }
            cout << "Invalid move" << endl;
        }

        if (checkWinRow(board) || checkWinColumn(board) || checkDiagonalWin(board))
        {
            cout << "Player 1 win" << endl;
            break;
        }

        if (!isEmpty(board))
        {
            renderTable(board);
            cout << "It's a draw!" << endl;
            break;
        }

        renderTable(board);

        cout << "Player 2: " << endl;
        while (1)
        {
            cout << "Enter the row(1-3): ";
            while (1)
            {
                cin >> row;
                if (row >= 1 && row <= 3)
                {
                    break;
                }
                cout << "Invalid move\nRe-enter the row: ";
            }
            cout << "Enter the column(1-3): ";
            while (1)
            {
                cin >> column;
                if (column >= 1 && column <= 3)
                {
                    break;
                }
                cout << "Invalid move\nRe-enter the column: ";
            }
            if (board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = 'O';
                break;
            }
            cout << "Invalid move" << endl;
        }

        if (checkWinRow(board) || checkWinColumn(board) || checkDiagonalWin(board))
        {
            cout << "Player 2 win" << endl;
            break;
        }

        if (!isEmpty(board))
        {
            renderTable(board);
            cout << "It's a draw!" << endl;
            break;
        }
    } while (1);
}

void PvAI(char board[3][3])
{

    do
    {
        renderTable(board);
        int row, column;
        while (1)
        {
            cout << "Enter the row(1-3): ";
            while (1)
            {
                cin >> row;
                if (row >= 1 && row <= 3)
                {
                    break;
                }
                cout << "Invalid move\nRe-enter the row: ";
            }
            cout << "Enter the column(1-3): ";
            while (1)
            {
                cin >> column;
                if (column >= 1 && column <= 3)
                {
                    break;
                }
                cout << "Invalid move\nRe-enter the column: ";
            }
            if (board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = 'X';
                break;
            }
            cout << "Invalid move" << endl;
        }

        if (checkWinRow(board) || checkWinColumn(board) || checkDiagonalWin(board))
        {
            cout << "Player win" << endl;
            break;
        }

        if (!isEmpty(board))
        {
            renderTable(board);
            cout << "It's a draw!" << endl;
            break;
        }

        while (1)
        {
            int computerMoveRow = (rand() % 3);
            int computerMoveColumn = (rand() % 3);
            if (board[computerMoveRow][computerMoveColumn] == ' ')
            {
                board[computerMoveRow][computerMoveColumn] = 'O';
                break;
            }
        }

        if (checkWinRow(board) || checkWinColumn(board) || checkDiagonalWin(board))
        {
            cout << "Machine win" << endl;
            break;
        }

        if (!isEmpty(board))
        {
            renderTable(board);
            cout << "It's a draw!" << endl;
            break;
        }

    } while (1);
}

void ticTacToe()
{
    int flag = 1, choice;

    do
    {
        cout << "TicTacToe" << endl
             << "1)Multiplayer" << endl
             << "2)Singleplayer" << endl
             << "0)Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            char board[3][3] = {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}};
            Pvp(board);
            cout << "Do you want to play again" << endl;
            break;
        case 2:
            char board[3][3] = {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}};
            PvAI(board);
            cout << "Do you want to play again" << endl;
            break;
        case 0:
            flag = 0;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (flag);
}

int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    ticTacToe();
    return 0;
}

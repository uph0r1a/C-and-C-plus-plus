#include <iostream>
using namespace std;

void displayBoard(char board[3][3])
{
    cout << "-------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|" << board[i][j];
        }
        cout << "|\n";
    }
    cout << "-------\n";
}

bool checkWin(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        if (board[i][0] != '*' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;

    for (int i = 0; i < 3; i++)
        if (board[0][i] != '*' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;

    if (board[1][1] != '*' &&
        ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
         (board[0][2] == board[1][1] && board[1][1] == board[2][0])))
        return true;

    return false;
}

bool boardFull(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '*')
                return false;
    return true;
}

int main()
{
    char board[3][3] = {
        {'*', '*', '*'},
        {'*', '*', '*'},
        {'*', '*', '*'}};

    int row, col;
    char player = 'X';

    cout << "Tic-Tac-Toe Game" << endl;

    while (true)
    {
        displayBoard(board);

        cout << "Player " << (player == 'X' ? 1 : 2) << " (" << player << ")" << endl;
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '*')
        {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = player;

        if (checkWin(board))
        {
            displayBoard(board);
            cout << "Player " << (player == 'X' ? 1 : 2) << " wins!" << endl;
            break;
        }

        if (boardFull(board))
        {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

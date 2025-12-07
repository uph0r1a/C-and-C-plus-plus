#include <iostream>
#include <cstring>
using namespace std;

void renderBoard(char board[3][3]){
    memset(board,' ',sizeof(board));

    cout<<--------------<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"|"<<board[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"------------"<<endl;
}

int main(int argc, char const *argv[])
{
    char board[3][3];
    renderBoard(board);
    return 0;
}

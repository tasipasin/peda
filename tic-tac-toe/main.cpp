#include <iostream>

using namespace std;

char playerX = 'x';
char playerO = 'o';

bool isPlayerWinner(const char board[3][3], char player)
{
    bool result = false;
    int i = 0;
    while (i < 3 && !result)
    {
        result = board[i][0] == player && board[i][1] == player && board[i][2] == player || board[0][i] == player && board[1][i] == player && board[2][i] == player;
        i++;
    }
    if (!result)
    {
        result = board[0][0] == player && board[1][1] == player && board[2][2] == player || board[0][2] == player && board[1][1] == player && board[2][0] == player;
    }
    return result;
}

bool isPlayerOrEmpty(const char board[3][3], char player, int row, int column)
{
    return board[row][column] == player || board[row][column] == ' ';
}

int evaluate(const char board[3][3], char player)
{
    char againstPlayer = player == playerX ? playerO : playerX;
    int playerCounter = 0;
    int againstCounter = 0;
    bool playerWinner = isPlayerWinner(board, player);
    bool againstWinner = isPlayerWinner(board, againstPlayer);
    int result = 0;

    if (!playerWinner && !againstWinner)
    {
        // Percorre as linhas de acordo
        for (int i = 0; i < 3; i++)
        {

            if (isPlayerOrEmpty(board, player, i, 0) && isPlayerOrEmpty(board, player, i, 1) && isPlayerOrEmpty(board, player, i, 2))
            {
                playerCounter++;
            }
            if (isPlayerOrEmpty(board, againstPlayer, i, 0) && isPlayerOrEmpty(board, againstPlayer, i, 1) && isPlayerOrEmpty(board, againstPlayer, i, 2))
            {
                againstCounter++;
            }
            if (isPlayerOrEmpty(board, player, 0, i) && isPlayerOrEmpty(board, player, 1, i) && isPlayerOrEmpty(board, player, 2, i))
            {
                playerCounter++;
            }
            if (isPlayerOrEmpty(board, againstPlayer, 0, i) && isPlayerOrEmpty(board, againstPlayer, 1, i) && isPlayerOrEmpty(board, againstPlayer, 2, i))
            {
                againstCounter++;
            }
        }
        if (isPlayerOrEmpty(board, player, 0, 0) && isPlayerOrEmpty(board, player, 1, 1) && isPlayerOrEmpty(board, player, 2, 2))
        {
            playerCounter++;
        }
        if (isPlayerOrEmpty(board, againstPlayer, 0, 0) && isPlayerOrEmpty(board, againstPlayer, 1, 1) && isPlayerOrEmpty(board, againstPlayer, 2, 2))
        {
            againstCounter++;
        }
        if (isPlayerOrEmpty(board, player, 0, 2) && isPlayerOrEmpty(board, player, 1, 1) && isPlayerOrEmpty(board, player, 2, 0))
        {
            playerCounter++;
        }
        if (isPlayerOrEmpty(board, againstPlayer, 0, 2) && isPlayerOrEmpty(board, againstPlayer, 1, 1) && isPlayerOrEmpty(board, againstPlayer, 2, 0))
        {
            againstCounter++;
        }
        cout << "player counter: " << playerCounter << endl;
        cout << "against counter: " << againstCounter << endl;
        result = playerCounter - againstCounter;
    }
    else if (playerWinner)
    {
        result = 9;
    }
    else
    {
        result = -9;
    }
    return result;
}

int main()
{
    char board[3][3] = {{' ', 'x', ' '}, {'x', 'o', ' '}, {' ', 'o', ' '}};
    cout << evaluate(board, 'x') << endl;
    return 0;
}
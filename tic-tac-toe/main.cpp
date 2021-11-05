#include <iostream>

using namespace std;

char playerX = 'x';
char playerO = 'o';

/**
 * Verifica se o jogador venceu a partida
 * @param board Tabuleiro do Jogo.
 * @param player Jogador.
 * @return Verdadeiro para jogador vencedor.
 */
bool isPlayerWinner(const char board[3][3], char player)
{
    // Inicializa o resultado como falso
    bool result = false;
    int i = 0;
    // Percorre o tabuleiro enquanto não achar vitória do jogador
    while (i < 3 && !result)
    {
        // Verifica linhas e colunas
        result = board[i][0] == player && board[i][1] == player && board[i][2] == player || board[0][i] == player && board[1][i] == player && board[2][i] == player;
        i++;
    }
    // Se ainda não tiver achado vitória do jogador, verifica nas diagonais
    if (!result)
    {
        result = board[0][0] == player && board[1][1] == player && board[2][2] == player || board[0][2] == player && board[1][1] == player && board[2][0] == player;
    }
    return result;
}

/**
 * Verifica se na posição do tabuleiro informada tem uma jogada ou vazio.
 * @param board Tabuleiro do Jogo.
 * @param player Jogador.
 * @param row   Valor da linha.
 * @param column Valor da coluna.
 * @return Verdadeiro para posição para o jogador ou vazia.
 */
bool isPlayerOrEmpty(const char board[3][3], char player, int row, int column)
{
    return board[row][column] == player || board[row][column] == ' ';
}

/**
 * Avalia a situação do Jogo para o jogador informado.
 * @param board Tabuleiro do Jogo.
 * @param player Jogador.
 * @return Quão bom está o jogo para o jogador.
 */
int evaluate(const char board[3][3], char player)
{
    // Determina qual o jogador contrário
    char againstPlayer = player == playerX ? playerO : playerX;
    // Inicializa contador de possivel jogada para o jogador
    int playerCounter = 0;
    // Inicializa contador de possivel jogada para o jogador contrário
    int againstCounter = 0;
    // Verifica se o jogador ganhou o jogo
    bool playerWinner = isPlayerWinner(board, player);
    // Verifica se o jogador contrário ganhou o jogo
    bool againstWinner = isPlayerWinner(board, againstPlayer);
    int result = 0;
    // Verifica se alguém ja ganhou o jogo
    if (!playerWinner && !againstWinner)
    {
        // Percorre as linhas de acordo
        for (int i = 0; i < 3; i++)
        {
            // Verifica se a linha pode ser jogada do jogador
            if (isPlayerOrEmpty(board, player, i, 0) && isPlayerOrEmpty(board, player, i, 1) && isPlayerOrEmpty(board, player, i, 2))
            {
                playerCounter++;
            }
            // Verifica se a linha pode ser jogada do jogador contrário
            if (isPlayerOrEmpty(board, againstPlayer, i, 0) && isPlayerOrEmpty(board, againstPlayer, i, 1) && isPlayerOrEmpty(board, againstPlayer, i, 2))
            {
                againstCounter++;
            }
            // Verifica se a coluna pode ser jogada do jogador
            if (isPlayerOrEmpty(board, player, 0, i) && isPlayerOrEmpty(board, player, 1, i) && isPlayerOrEmpty(board, player, 2, i))
            {
                playerCounter++;
            }
            // Verifica se a coluna pode ser jogada do jogador contrário
            if (isPlayerOrEmpty(board, againstPlayer, 0, i) && isPlayerOrEmpty(board, againstPlayer, 1, i) && isPlayerOrEmpty(board, againstPlayer, 2, i))
            {
                againstCounter++;
            }
        }
        // Verifica se a diagonal principal podem ser jogada do jogador
        if (isPlayerOrEmpty(board, player, 0, 0) && isPlayerOrEmpty(board, player, 1, 1) && isPlayerOrEmpty(board, player, 2, 2))
        {
            playerCounter++;
        }
        // Verifica se a diagonal principal podem ser jogada do jogador contrário
        if (isPlayerOrEmpty(board, againstPlayer, 0, 0) && isPlayerOrEmpty(board, againstPlayer, 1, 1) && isPlayerOrEmpty(board, againstPlayer, 2, 2))
        {
            againstCounter++;
        }
        // Verifica se a diagonal secundária podem ser jogada do jogador
        if (isPlayerOrEmpty(board, player, 0, 2) && isPlayerOrEmpty(board, player, 1, 1) && isPlayerOrEmpty(board, player, 2, 0))
        {
            playerCounter++;
        }
        // Verifica se a diagonal secundária podem ser jogada do jogador contrário
        if (isPlayerOrEmpty(board, againstPlayer, 0, 2) && isPlayerOrEmpty(board, againstPlayer, 1, 1) && isPlayerOrEmpty(board, againstPlayer, 2, 0))
        {
            againstCounter++;
        }
        cout << "player counter: " << playerCounter << endl;
        cout << "against counter: " << againstCounter << endl;
        cout << playerCounter - againstCounter << endl;
    }
    // Verifica se o jogador venceu
    else if (playerWinner)
    {
        cout << "9 (" << player << " ganhou)" << endl;
    }
    // Se o jogador perdeu
    else
    {
        cout << "-9 (" << player << " perdeu)" << endl;
    }
    return result;
}

int main()
{
    // Define o estado do jogo da velha
    char board[3][3] = {{' ', 'x', 'o'}, {'x', 'o', ' '}, {'o', 'o', ' '}};
    // Imprime o jogo da velha
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl
             << "-+-+-" << endl;
    }
    evaluate(board, 'x');
    return 0;
}
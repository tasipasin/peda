#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include "Position.h"

using namespace std;

// Inicialização do labirinto
vector<string> labirinto = {
    "XXXXXXXXXXXXXXXXSXXXX",
    "X     X     X     X X",
    "XX XX XXXXX X X X   X",
    "X   X       XXX XXX X",
    "X X X XXXXXXX   X   X",
    "X X   X   X X X   X X",
    "X XXXXX X X   XXXXX X",
    "X X     X XXX  X    X",
    "X X X X X   XX XX XXX",
    "X X XXX X X     X   X",
    "E X X X X XXXXX XXX X",
    "X     X X   X X X   X",
    "X XXXXX XXX X XXX X X",
    "X X       X X   X X X",
    "X   XXX X X XXX X X X",
    "XXX X X X X X X X XXX",
    "X X   X X   X   X   X",
    "X XXX XXXXXXXXX XXX X",
    "X                 X X",
    "XXXXXXXXXXXXXXXXXXXXX"};

// Inicialização do ponto de entrada do labirinto
Position entryPoint;
// Inicialização da pilha do caminho percorrido
stack<Position> wayToGo;
// Inicialização da pilha de caminhos "sem saída"
stack<Position> wayNotToGo;

/*
    Verifica se pode caminhar para a próxima posição indicada pelas variáveis x e y
    @param position Posição atual;
    @param x Quantidade de passos para somar em x.
    @param y Quantidade de passos para somar em y.
    @return Verdadeiro se é permitido caminhar para o caminho informado.
*/
bool canWalkNext(Position position, int x, int y)
{
    // Inicializa a variável de retorno
    bool result = false;
    //Recupera o valor da possível proxima posição em X
    int xSize = position.getX() + x;
    // Verifica se a próxima posição está dentro do labirinto
    if (xSize >= 0 && xSize < labirinto.size())
    {
        // Recupera o valor da possível proxima posição em Y
        int ySize = position.getY() + y;
        // Verifica se a próxima posição está dentro do labirinto
        if (ySize >= 0 && ySize < labirinto[xSize].size())
        {
            // Recupera a proxima posição
            char nextPostChar = labirinto[xSize].at(ySize);
            // Verifica se não é parede ou o próprio caminho
            result = (nextPostChar != 'X' && nextPostChar != '*' && nextPostChar != 'E');
        }
    }
    return result;
}

/*
    Verifica se a posição informada já foi visitada e não é um caminho.
    @param position Posição para verificação.
    @param pathToCheck Pilha de posições que não são caminho.
    @return Verdadeiro se for uma posição que não é caminho.
*/
bool goneHere(Position position, stack<Position> pathToCheck)
{
    // Inicializa variável de retorno
    bool result = false;
    // Executa enquanto o resultado for falso e não tiver chego ao fim da pilha
    while (!result && !pathToCheck.empty())
    {
        // Recupera a próxima posição da pilha
        Position gonePosition = pathToCheck.top();
        // Verifica se são iguais e atualiza a variável de retorno
        result = gonePosition.isEquals(position);
        // Retira a posição da pilha
        pathToCheck.pop();
    }
    return result;
}

/*
    Verifica se a posição informada já foi visitada e não é um caminho.
    @param position Posição para verificação.
    @return Verdadeiro se for uma posição que não é caminho.
*/
bool goneHere(Position position)
{
    // Verifica se a posição informada já foi visitada e não é um caminho.
    return goneHere(position, wayNotToGo);
}

/*
    Imprime o labirinto resolvido.
*/
void printLabyrinth()
{
    // Limpa o terminal
    system("CLS");
    // Imprime cabeçalho do labirinto
    cout << "* * * LABIRINTO * * *" << endl;
    // Imprime o valor da entrada
    cout << "Entrada: (" << entryPoint.getX() << ", " << entryPoint.getY() << ")" << endl
         << endl;
    // Percorre os vetores de labirinto
    for (int x = 0; x < labirinto.size(); x++)
    {
        // Imprime o vetor inteiro do labirinto
        cout << labirinto[x] << endl;
    }
    // Imprime a posição de saída do labirinto, que é o objeto no topo da pilha de caminhos percorridos
    cout << endl
         << "Saida: (" << wayToGo.top().getX() << ", " << wayToGo.top().getY() << ")" << endl;
}

/*
    Realiza busca do ponto de entrada do labirinto.
    @return Retorna o objeto de posição com os valores da entrada.
*/
Position findEntryPoint()
{
    // Inicializa a variável de retorno
    Position result(-1, -1);
    // Inicializa verificador de caminho encontrado
    bool foundEntryPoint = false;
    // Recupera a quantidade máxima de x
    int xMaxSize = labirinto.size();
    // Inicializa x
    int x = 0;
    // Percorre os arrays de labirinto enquando x for menor que o valor máximo de x
    // e enquando o verificador de caminho encontrado for falso
    while (x < xMaxSize && !foundEntryPoint)
    {
        // Recupera o valor máximo de y para cada x
        int yMaxSize = labirinto[x].size();
        // Verifica a linha inteira se for o primeiro ou o último vetor
        // e enquando o verificador de caminho encontrado for falso
        if ((x == 0 || x == (xMaxSize - 1)) && !foundEntryPoint)
        {
            // Inicializa y
            int y = 0;
            // Percorre o labirinto enquanto y for menor que a quantidade máxima de y
            // e enquando o verificador de caminho encontrado for falso
            while (y < yMaxSize && !foundEntryPoint)
            {
                // Recupera o caracter na posição
                char currChar = labirinto[x].at(y);
                // Verifica se o caracter é o de entrada
                if (currChar == 'E')
                {
                    // Adiciona o objeto de posição na variável de retorno
                    result = Position(x, y);
                    // Atualiza o verificador de caminho para verdadeiro
                    foundEntryPoint = true;
                }
                // incrementa Y
                y++;
            }
        }
        // Verifica as pontas das linhas
        // enquando o verificador de caminho encontrado for falso
        if (!foundEntryPoint)
        {
            // Recupera o primeiro caracter da linha
            char zeroChar = labirinto[x].at(0);
            // Recupera o último caracter da linha
            char lastChar = labirinto[x].at(yMaxSize - 1);
            // Verifica se o primeiro caracter é o de entrada
            if (zeroChar == 'E')
            {
                // Adiciona o objeto de posição na variável de retorno
                result = Position(x, 0);
                // Atualiza o verificador de caminho para verdadeiro
                foundEntryPoint = true;
            }
            // Verifica se o primeiro caracter é o de entrada
            else if (lastChar == 'E')
            {
                // Adiciona o objeto de posição na variável de retorno
                result = Position(x, yMaxSize - 1);
                // Atualiza o verificador de caminho para verdadeiro
                foundEntryPoint = true;
            }
        }
        // Incrementa x
        x++;
    }
    // Atribui o resultado na variável global do ponto de entrada
    entryPoint = result;
    return result;
}

/*
    Método main.
 */
int main()
{
    // Inicia o contador de quantas iterações foram necessárias para encontrar o caminho
    int loopNumber = 0;
    // Define o início do labirinto
    Position currentPosition = findEntryPoint();
    // Inicializa verificador de saída de labirinto encontrada
    // Se não for encontrado caminho para o labirinto, inicia como verdadeiro
    // para que a rotina de busca nem comece
    bool ended = currentPosition.getX() == -1 && currentPosition.getY() == -1;
    // Adiciona a posição atual na pilha de caminho percorrido
    wayToGo.push(currentPosition);
    // Altera o caracter da posição para asterisco
    labirinto[currentPosition.getX()].at(currentPosition.getY()) = '*';
    // Busca o caminho enquanto o verificador de saída de labirinto encontrada seja falso
    while (!ended)
    {
        // Inicializa verificador de caminho escolhido
        bool wayChoosed = false;
        // Inicializa posição temporária
        Position tempPos;
        // Verifica se é possível caminhar para a baixo
        if (!wayChoosed && canWalkNext(currentPosition, 1, 0))
        {
            // Define a posição temporária como o caminho de baixo
            tempPos = Position(currentPosition.getX() + 1, currentPosition.getY());
            // Verifica se o caminho já foi percorrido e não é caminho solução
            wayChoosed = !goneHere(tempPos);
        }
        // Verifica se é possível caminhar para direita
        if (!wayChoosed && canWalkNext(currentPosition, 0, 1))
        {
            // Define a posição temporária como o caminho de direita
            tempPos = Position(currentPosition.getX(), currentPosition.getY() + 1);
            // Verifica se o caminho já foi percorrido e não é caminho solução
            wayChoosed = !goneHere(tempPos);
        }
        // Verifica se é possível caminhar para a cima
        if (!wayChoosed && canWalkNext(currentPosition, -1, 0))
        {
            // Define a posição temporária como o caminho de cima
            tempPos = Position(currentPosition.getX() - 1, currentPosition.getY());
            // Verifica se o caminho já foi percorrido e não é caminho solução
            wayChoosed = !goneHere(tempPos);
        }
        // Verifica se é possível caminhar para esquerda
        if (!wayChoosed && canWalkNext(currentPosition, 0, -1))
        {
            // Define a posição temporária como o caminho de esquerda
            tempPos = Position(currentPosition.getX(), currentPosition.getY() - 1);
            // Verifica se o caminho já foi percorrido e não é caminho solução
            wayChoosed = !goneHere(tempPos);
        }
        // Se não der para andar para os caminhos, volta 1
        if (!wayChoosed)
        {
            // Volta o caracter do labirinto para espaço, indicando caminho vazio
            labirinto[currentPosition.getX()].at(currentPosition.getY()) = ' ';
            // Insere a posição atual na pilha de caminhos que não são caminhos solução
            wayNotToGo.push(currentPosition);
            // Remove o último caminho percorrido da pilha de caminhos solução
            wayToGo.pop();
            // Recupera o caminho que está no topo da pilha de caminhos solução
            currentPosition = wayToGo.top();
        }
        else
        {
            // Verifica se o caminho atual é a saída do labirinto
            ended = labirinto[tempPos.getX()].at(tempPos.getY()) == 'S';
            // Atualiza a posição atual com a posição temporária
            currentPosition = tempPos;
            // Adiciona a posição atual no pilha de caminhos solução
            wayToGo.push(currentPosition);
            // Atualiza o valor do caracter atual como asterisco
            labirinto[currentPosition.getX()].at(currentPosition.getY()) = '*';
        }
        // Incrementa a iteração
        loopNumber++;
    }
    // Imprime o labirinto resolvido
    printLabyrinth();
    return 0;
}
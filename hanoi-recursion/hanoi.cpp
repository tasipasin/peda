#include <iostream>

using namespace std;

// Inicializa a lista de hastes disponiveis
char availableRods[] = {'A', 'B', 'C'};

/**
 * Executa recursividade para resolucao da torre re Hanoi.
 */
void hanoiTower(int qtdDiscos, char hasteOrigem, char hasteDestino, char hasteAuxiliar) {
    // Se houver apenas um disco, move direto para a haste de origem. Caso basico
    if (qtdDiscos == 1) {
        cout << "Movido disco 1 da haste " << hasteOrigem << " para a haste " << hasteDestino << endl;
    } else {
        // A intencao e construir uma torre com n-1 discos na torre auxiliar,
        // transferir o n-esimo disco para o destino, e depois transferir a torre
        // de n-1 discos para a origem.

        // Aqui eh resolvido o problema para n-1 discos, assumindo a torre auxiliar
        // como torre de destino, e a torre de destino como torre auxiliar
        hanoiTower(qtdDiscos - 1, hasteOrigem, hasteAuxiliar, hasteDestino);
        // Imprime o disco que esta sendo movido, e para qual haste
        cout << "Movido disco " << qtdDiscos << " da haste " << hasteOrigem <<
             " para a haste " << hasteDestino << endl;
        // Aqui eh resolvido o problema para n-1 discos, mas assumindo a torre auxiliar como
        // torre de origem e a torre de origem como torre auxiliar
        hanoiTower(qtdDiscos - 1, hasteAuxiliar, hasteDestino, hasteOrigem);
    }
}

/**
 * Apresenta as opcoes validas de Hastes.
 */
void printAvailableRods() {
    cout << "(Hastes disponiveis: ";
    for (int i = 0; i < sizeof(availableRods); i++) {
        // Recupera o char atual
        char currentRod = availableRods[i];
        // Verifica se o char atual eh espaco, quer dizer que eh o final das opcoes
        if(isspace(availableRods[i + 1]) && i < (sizeof(availableRods) - 1)) {
            i = (sizeof(availableRods) - 1);
        }
        cout << currentRod;
        // Verifica se existem mais hastes
        if(i < (sizeof(availableRods) - 1)) {
            // Adiciona virgula e espaco
            cout << " ";
        } else {
            // Fecha parenteses e pula linha
            cout << ")" << endl;
        }
    }
}

/**
 * Retorna o valor da posicao da haste selecionada.
 * @param selectedRod Haste selecionada.
 * @return Retorna o valor da posicao da haste selecionada, ou -1 se nao for encontrada.
 */
int getRodPosition(char selectedRod) {
    // Inicializa variavel de retorno
    int result = -1;
    // Inicializa valor de posicao atual
    int actualPos = 0;
    // Percorre a array de caracteres enquanto nao tiver resultado ou
    // ate ter terminado a array
    while(result == -1 && actualPos < sizeof(availableRods)) {
        // Recupera o char da posicao atual
        char rod = availableRods[actualPos];
        // Verifica se sao iguals
        if(rod == selectedRod) {
            // Adiciona a posicao atual na varaavel de retorno
            result = actualPos;
        } else {
            // Incrementa a posicao atual da busca
            actualPos++;
        }
    }
    return result;
}

/**
 * Remove a haste selecionada.
 * @param selectedRod Haste selecionada.
 * @return Verdadeiro para haste removida, falso para haste nao encontrada/removida.
 */
bool removeSelectedRod(char selectedRod) {
    // Inicializa indicador de sucesso para retorno
    bool result = false;
    // Recupera a posicao, se existir, da haste selecionada
    int selectedRodPosition = getRodPosition(selectedRod);
    // Verifica se o char foi encontrado
    if(selectedRodPosition != -1) {
        // Inicializa novo valor do tamanho do array de hastes disponiveis
        int newArraySize = sizeof(availableRods) - 1;
        // Percorre a array de hastes disponiveis a partir da posicao da haste selecionada
        for(int i = selectedRodPosition; i < newArraySize ; i++) {
            // Substituindo os valores pelos valores da proxima posicao
            availableRods[i] = availableRods[i+1];
        }
        availableRods[newArraySize] = ' ';
        result = true;
    }
    return result;
}

/**
 * Executa processo de leitura de Haste.
 * @param rod String contendo qual a haste sendo selecionada.
 * @return Retorna a haste lida transformada em maiuscula, se ja nao estiver.
 */
char readRod(const char* rod) {
    char userRod;
    // Requisita qual sera a haste de origem
    while (true) {
        cout << "Defina a haste de " << rod <<": \n";
        // Apresenta as hastes disponiveis
        printAvailableRods();
        do {
            userRod = getchar();
        } while(isspace(userRod));
        // Transforma o char inserido para maiusculo
        userRod = toupper(userRod);
        // Verifica valor invalido
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Valor Invalido" << endl;
        }
        // Tenta remover a haste selecionada
        else if(!removeSelectedRod(userRod)) {
            cin.clear();
            cin.ignore();
            cout << "A haste nao existe como opcao" << endl;
        } else {
            cin.clear();
            break;
        }
    }
    return userRod;
}

/**
 * Metodo inicial e principal do programa.
 * @return int Retorno de finalizacao do programa.
 */
int main() {
    // Inicializa as variaveis que irao armazenar as preferencias de hastes do usuario
    char hasteOrigem, hasteDestino;
    // Inicializa quantidade de discos com valor padrao
    int qtdDiscos = -1;
    // Requisita a quantidade de discos para o usuario enquanto o valor nao for valido
    while (true) {
        cout << "Entre com a quantidade de discos a serem movidos: " << endl;
        cin >> qtdDiscos;
        // Verifica valor invalido
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Valor Invalido" << endl;
        } else {
            cin.clear();
            cout << endl;
            break;
        }
    }
    // Le a haste de origem do usuario
    hasteOrigem = readRod("origem");
    cout << endl;
    // Le a haste de destino do usuario
    hasteDestino = readRod("destino");
    cout << endl << endl;
    // Executa a transferencia dos discos na torre de Hanoi
    hanoiTower(qtdDiscos, hasteOrigem, hasteDestino, availableRods[0]);
    return 0;
}


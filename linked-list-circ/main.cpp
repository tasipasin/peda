#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "List.h"

using namespace std;

// Nome do arquivos para criptografia
string fileName = "";
// Extensão do arquivo criptografado
string outputExtension = "jcripto";
// Número de pulos para extração
int jumps;

/**
 * Executa a criptografia baseada no algoritmo de Josefo.
 * @param toEncrypt Lista de Strings para serem criptografadas.
 * @return Retorna a lista de linhas criptografadas.
 */
list<string> josephusEncript(list<string> toEncrypt)
{
    // Inicializa variável de retorno
    list<string> result;
    // Percorre as strings da lista
    for (auto const &toEncryptStr : toEncrypt)
    {
        // Inicializa a lista de caracteres para criptografia
        List *toCript = new List();
        // Percorre a string
        for (int count = 0; count < toEncryptStr.length(); count++)
        {
            // Recupera o char na posição atual
            char charAt = toEncryptStr.at(count);
            // Insere o caractere na lista de caracteres
            toCript->insert(charAt);
        }
        // Inicializa a string com para a linha criptografada
        string preResult = "";
        // Enquanto a lista de caracteres não estiver vazia
        while (!toCript->empty())
        {
            // Pula as posições de acordo com a entrada
            for (int i = 1; i < jumps; i++)
            {
                toCript->next();
            }
            // Recupera o char da posição e remove
            char charTmp = toCript->remove();
            // Adiciona na string para linha criptografada
            preResult.push_back(charTmp);
        }
        // Adiciona a linha criptografada na lista de resultado
        result.emplace_back(preResult);
    }
    return result;
}

/**
 * Executa leitura do teclado validando de acordo com o tipo informado.
 * @param message Mensagem para aparecer na requisição da entrada.
 */
static string readString(string message)
{
    string result;
    // Requisita o nome do arquivo de entrada
    while (true)
    {
        cout << message << endl;
        getline(cin, result);
        // Verifica valor invalido
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Valor Invalido" << endl;
        }
        else
        {
            cin.clear();
            break;
        }
    }
    return result;
}

/**
 * Executa leitura do teclado validando de acordo com o tipo informado.
 * @param message Mensagem para aparecer na requisição da entrada.
 */
static int readInt(string message)
{
    int result;
    while (true)
    {
        cout << message << endl;
        cin >> result;
        // Verifica valor invalido
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Valor Invalido" << endl;
        }
        else
        {
            cin.clear();
            break;
        }
    }
    return result;
}

/**
 * Programa principal.
 * @return Código de fim de programa.
 */
int main()
{
    // Inicializa lista de strings para serem criptografadas
    list<string> toEncrypt;
    // Realiza leitura do nome do arquivo
    fileName = readString("Entre com o nome do arquivo (.txt): ");
    // Lê arquivos
    ifstream myfile(fileName);
    // Verifica se o arquivo está aberto
    if (myfile.is_open())
    {
        // Lê todas as linhas do arquivo
        while (!myfile.eof())
        {
            string toCripto;
            getline(myfile, toCripto);
            toEncrypt.emplace_back(toCripto);
        }
        // Fecha o arquivo
        myfile.close();
        // Realiza leitura do valor do pulo
        jumps = readInt("Entre com a quantidade de pulos para extracao: ");
        // Executa criptografia
        list<string> criptResult = josephusEncript(toEncrypt);
        // Verifica se o resultado da criptografia é diferente de nulo
        if (!criptResult.empty())
        {
            // Inicializa stream para escrever no arquivo
            ofstream encryptedFile(fileName.substr(0, fileName.size() - 3) + outputExtension);
            // Percorre as linhas
            for (auto const &i : criptResult)
            {
                // Insere as linhas no arquivo de saída
                encryptedFile << i << endl;
            }
            // Fecha o arquivo
            encryptedFile.close();
        }
    }
    else
    {
        cout << "O arquivo nao pode ser aberto";
    }
}
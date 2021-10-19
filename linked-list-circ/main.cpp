#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "List.h"

using namespace std;

int main()
{
    string cripted = "CFBGEAD";
    int m = 3;
    // Inicializa a lista de caracteres para criptografia
    List *toCript = new List();
    // Percorre a string
    for (int count = 0; count < cripted.length(); count++)
    {
        // Recupera o char na posição atual
        char charAt = cripted.at(count);
        // Insere o caractere na lista de caracteres
        toCript->insert(charAt);
    }
    string temp = "";
    int total = cripted.length();
    while (!toCript->empty())
    {
        for(int i = 0; i < m; i++){
            
        }
        cout << toCript->getNumNodes() << endl;
        toCript->remove();
    }
}
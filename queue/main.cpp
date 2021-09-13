#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue fila;

    // Requisita a quantidade de discos para o usuario enquanto o valor nao for valido
    while (true && !fila.full()) {
        int newNumber;
        cout << "Entre com um valor maior que zero: " << endl;
        cin >> newNumber;
        // Verifica valor invalido
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Valor Invalido" << endl;
        } else if (newNumber < 0){
            break;
        }else{
            fila.insert_desc(newNumber);
        }
    }
    fila.printQueue();
}
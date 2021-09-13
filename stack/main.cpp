#include<iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack pilha;

    pilha.push(10);
    pilha.push(9);
    pilha.push(8);
    pilha.push(7);
    pilha.push(6);
    pilha.push(5);
    pilha.push(4);
    pilha.push(3);
    pilha.push(2);
    pilha.push(1);

    pilha.showStack();
    int aa = 0;
    cin >> aa;

    return 0;
}
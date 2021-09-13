#include<iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(void)
{
    Stack::topElement_ = -1;
}

/// <summary> Insere o novo elemento na pilha.</summary>
void Stack::push(DataType element)
{
    // Verifica se a pilha não está cheia
    if (!full())
    {
        // Incrementa o valor do topo
        ++topElement_;
        // Insere o elemento no novo topo
        data[topElement_] = element;
    }
    else
    {
        // Exibe mensagem de pilha cheia
        cerr << "Pilha cheia" << endl;
    }
}

/// <summary> Retira o elemento do topo da Pilha.</summary>
void Stack::pop()
{
    // Verifica se a pilha não está vazia
    if (!empty())
    {
        // Atribui o valor do antigo topo 
        data[topElement_] = -1;
        // Decrementa o valor do topo
        --topElement_;
    }
    else
    {
        // Exibe mensagem de pilha vazia
        cerr << "Pilha vazia" << endl;
    }
}

/// <summary> Retorna o valor do topo da pilha.</summary>
/// <returns> Retorna o valor do topo da pilha. -1 para pilha vazia. </returns>
DataType Stack::top()
{
    DataType result = -1;
    // Verifica se a pilha não está vazia
    if (!empty())
    {
        // Recupera o valor do topo
        result = data[topElement_];
    }
    else
    {
        // Exibe mensagem de pilha vazia
        cerr << "Pilha vazia" << endl;
    }
    return result;
}

/// <summary> Verifica se a pilha está vazia.</summary>
/// <returns> Retorna verdadeiro para pilha vazia. </returns>
bool Stack::empty()
{
    return (topElement_ == -1);
}

/// <summary> Retorna verdadeiro para pilha cheia.</summary>
/// <returns> Retorna verdadeiro para pilha cheia.</returns>
bool Stack::full()
{
    return (topElement_ == (MAXPILHA - 1));
}

/// <summary> Verifica se a pilha está vazia.</summary>
void Stack::showStack()
{
    int pos;
    if (!empty())
    {
        for (pos = 0; pos < MAXPILHA; pos++)
        {
            cout << "Posicao: " << pos << endl;
            cout << "Valor: " << data[pos] << endl
                 << endl;
        }
    }
}
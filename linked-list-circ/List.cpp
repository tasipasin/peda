#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
    list = nullptr;
    numNodes = 0;
} // cria lista vazia (construtor)

List::~List()
{
    cout << "Cleaning memory" << endl;
    while (!empty())
    {
        cout << remove() << endl;
    }
} // destrutor: esvazia a lista (liberando memória dos nós criados)

// insere x na lista
void List::insert(DataType x)
{
    Node *newNode = new Node;
    newNode->info = x;
    if (!empty())
    {
        newNode->prox = list->prox;
        list->prox = newNode;
    }
    else
    {
        newNode->prox = newNode;
    }
    list = newNode;
    ++numNodes;
}

DataType List::remove()
{
    DataType aux;
    if (!empty())
    {
        Node *rem = list->prox;
        list->prox = rem->prox;
        aux = rem->info;
        delete rem;
        --numNodes;
        if (numNodes == 0)
        {
            list = nullptr;
        }
    }
    else
    {
        cerr << "Empty List" << endl;
    }
    return aux;
} // remove elemento da lista

// retorna o núm. de elementos na lista
unsigned int List::tam()
{
    return numNodes;
}

// true, se lista vazia
bool List::empty()
{
    return (numNodes == 0);
}

// percorre a lista mostrando seus elem. na tela
void List::print()
{
    Node *tmp = list;
    while (tmp != nullptr)
    {
        cout << tmp->info << " ";
        tmp = tmp->prox;
    }
    cout << endl;
}

void List::next() {
    list = list->prox;
}

int List::getNumNodes(){
    return this->numNodes;
}
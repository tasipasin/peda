#ifndef LIST_H
#define LIST_H

using DataType = char;    // ou: typedef char TipoDado;

struct Node {
     DataType info;
     Node *prox;
};

class List
{
protected:
    Node *list;            // ponteiro para o primeiro nó da lista
    unsigned int numNodes; // número de nós da lista
public:
    List();                  // cria lista vazia (construtor)
    ~List();                 // destrutor: esvazia a lista (liberando memória dos nós criados)
    void insert(DataType x); // insere x na lista
    DataType remove();       // remove elemento da lista
    unsigned int tam();      // retorna o núm. de elementos na lista
    bool empty();            // true, se lista vazia
    void print();            // percorre a lista mostrando seus elem. na tela
    void next();
};
#endif
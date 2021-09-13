#include "Queue.h"
#include <iostream>

using namespace std;

int next(int i)
{
    return (i + 1) % MAX_QUEUE;
}

Queue::Queue()
{
    front_ = 0;
    back_ = 0;
}

void Queue::insert(DataType element)
{
    if (!full())
    {
        data[back_] = element;
        back_ = next(back_);
    }
    else
    {
        cerr << "Fila cheia." << endl;
    }
}

DataType Queue::front()
{
    DataType result = -1;
    if (!empty())
    {
        result = data[front_ - 1];
    }
    else
    {
        cerr << "Fila vazia." << endl;
    }
    return result;
}

void Queue::remove()
{
    if (!empty())
    {
        front_ = next(front_);
    }
    else
    {
        cerr << "Fila vazia." << endl;
    }
}

bool Queue::empty()
{
    return front_ == back_;
}

bool Queue::full()
{
    return (next(back_) == front_);
}

void Queue::printQueue()
{
    if (!empty())
    {
        int currPos = front_;
        while (currPos != back_)
        {
            cout << "Posicao: " << currPos << endl;
            cout << "Valor: " << data[currPos] << endl
                 << endl;
            currPos = next(currPos);
        }
    }
    else
    {
        cout << "Lista Vazia" << endl;
    }
}

void Queue::insert_desc(DataType element)
{
    if (!full())
    {
        if (empty())
        {
            insert(element);
        }
        else
        {
            // Começa a procurar a posição do item pelo final da fila
            int newPos = front_;
            // Recupera o valor da posição atual
            int currVal = data[newPos];
            // Verifica se o valor da posição atual é menor que o valor
            // do elemento sendo inserido
            while (currVal < element)
            {
                // Recupera a próxima posição
                newPos = next(newPos);
                // Recupera o valor da próxima posição
                currVal = data[newPos];
            }
            // Executa uma iteração para que a fila dê um passinho para tras
            for (int endQueue = back_; endQueue >= newPos; endQueue--)
            {
                int tempNewPos = next(endQueue);
                data[tempNewPos] = data[endQueue];
            }
            // Adiciona o novo elemento no novo lugar
            data[newPos] = element;
            // Incrementa o valor do fim da fila
            back_ = next(back_);
        }
    }
    else
    {
        cerr << "Fila cheia!" << endl;
    }
}
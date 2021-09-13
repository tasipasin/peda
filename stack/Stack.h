#ifndef STACK_H
#define STACK_H

#include <array>

using namespace std;

constexpr int MAXPILHA = 10;
using DataType = int;

class Stack
{
private:
    array<DataType, MAXPILHA> data;
    int topElement_;

public:
    // Construtor padrão
    Stack();
    void push(DataType element);
    void pop();
    DataType top();
    bool empty();
    bool full();
    void showStack();
};
#endif
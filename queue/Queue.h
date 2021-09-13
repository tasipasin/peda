#ifndef QUEUE_H
#define QUEUE_H

#include <array>

constexpr int MAX_QUEUE = 10;
using DataType = int;

class Queue
{
private:
    std::array<DataType, MAX_QUEUE> data;
    int front_;
    int back_;

public:
    Queue();
    void insert(DataType element);
    DataType front();
    void remove();
    bool empty();
    bool full();
    void printQueue();
    void insert_desc(DataType element);
};
#endif
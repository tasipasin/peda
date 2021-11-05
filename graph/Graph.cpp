#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int node_num)
{
    N = node_num;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            adj[i][j] = false;
        }
    }
}
void Graph::unify(int a, int b)
{
    if (validate(a, b))
    {
        adj[a][b] = true;
    }
}
void Graph::unify(int a, int b, float p)
{
    if (validate(a, b))
    {
        adj[a][b] = true;
        weight[a][b] = p;
    }
}
void Graph::remove(int a, int b)
{
    if (validate(a, b))
    {
        adj[a][b] = false;
    }
}
bool Graph::adjacent(int a, int b) const
{
    bool result = false;
    if (validate(a, b))
    {
        result = adj[a][b];
    }
    return result;
}
void Graph::print() const
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }
}

bool Graph::validate(int a, int b) const
{
    return a >= 0 && a < N && b >= 0 && b < N;
}
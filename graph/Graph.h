#ifndef GRAPH_H
#define GRAPH_H

constexpr int MAXNODES = 100;

class Graph
{
public:
    Graph(int node_num);
    void unify(int a, int b);
    void unify(int a, int b, float p);
    void remove(int a, int b);
    bool adjacent(int a, int b) const;
    void print() const;
private:
    bool adj[MAXNODES][MAXNODES];
    float weight[MAXNODES][MAXNODES];
    bool validate(int a, int b) const;
    int N;
};
#endif
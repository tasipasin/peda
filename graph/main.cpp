#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{

    Graph g(5);

    g.unify(0, 1);
    g.unify(1, 2);
    g.unify(2, 3);
    g.unify(3, 4);
    g.unify(4, 0);

    g.print();
}
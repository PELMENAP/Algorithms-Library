#include <bits/stdc++.h>

#include "visual.hpp"
#include "sortalg.h"
#include "graphalg.hpp"

using namespace std;
using namespace graphalgs;


void GraphTest()
{
    Graph_ml undirectedGraph(5, false);

    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 4);

    cout << "Undirected Graph - Adjacency List:" << endl;
    undirectedGraph.printGraphList();

    cout << "Undirected Graph - Matrix:" << endl;
    undirectedGraph.printGraphMatrix();

    cout << "Undirected Graph - DFS from vertex 0:" << endl;
    

    cout << "DFS starting from vertex 2:" << endl;
    vector<int> dfsResult = undirectedGraph.DFS(2);
    for (int v : dfsResult) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Iterative DFS starting from vertex 2:" << endl;
    vector<int> dfsIterativeResult = undirectedGraph.DFSIterative(2);
    for (int v : dfsIterativeResult) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(2);
    signed TT = 1;
    while (TT--)
    {
        GraphTest();
    }
    return 0;
}


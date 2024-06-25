#include <bits/stdc++.h>

#include "visual.hpp"
#include "sortalg.h"
#include "graphalg.hpp"

using namespace std;
using namespace graph;


void GraphTest()
{
    Graph undirectedGraph(5, false);

    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 4);

    cout << "Undirected Graph - Adjacency List:" << endl;
    undirectedGraph.printGraphList();

    cout << "Undirected Graph - DFS from vertex 0:" << endl;
    unordered_map<int, bool> visited;
    for (int i = 0; i < 5; ++i) {
        visited[i] = false;
    }
}

void solve()
{
    
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
        solve();
    }
    return 0;
}


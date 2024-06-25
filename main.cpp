#include <bits/stdc++.h>

#include "visual.hpp"
#include "sortalg.h"

using namespace std;

void DFS(const Graph& graph, int startVertex, unordered_map<int, bool>& visited) {
    stack<int> stack;
    stack.push(startVertex);

    int count = 0;

    while (!stack.empty()) {
        count++;
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
        }
        
        if(count > 1) break;

        const auto& neighbors = graph.getGraphList().at(vertex);
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            cout << it << endl;
            if (!visited[*it]) {
                stack.push(*it);
            }
        }
    }
}

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
    DFS(undirectedGraph, 0, visited);
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


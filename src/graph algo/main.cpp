#include <bits/stdc++.h>

#include "graphalgo.hpp"

using namespace std;
using namespace graphalgs;


void GraphTest()
{
    // Graph_ml undirectedGraph(9, false);

    // undirectedGraph.addEdge(0, 1);
    // undirectedGraph.addEdge(3, 4);
    // undirectedGraph.addEdge(1, 2);
    // undirectedGraph.addEdge(1, 4);
    // undirectedGraph.addEdge(2, 3);
    // undirectedGraph.addEdge(5, 6);
    // undirectedGraph.addEdge(7, 6);

    // cout << "Неориентированный граф - список смежности:" << endl;
    // undirectedGraph.printGraphList();
    // cout << "Неориентированный граф - матрица смежности:" << endl;
    // undirectedGraph.printGraphMatrix();


    // cout << "DFS с вершины 0:" << endl;
    // vector<int> dfsResult = undirectedGraph.DFSIterative(0);
    // for (int v : dfsResult) 
    //     cout << v << " ";
    // cout << endl;
    // cout << "BFS с вершины 4:" << endl;
    // vector<int> bfsIterativeResult = undirectedGraph.BFSIterative(4);
    // for (int v : bfsIterativeResult) 
    //     cout << v << " ";
    // cout << endl;

    // unordered_map<int, int> coloring = checkBipartite(undirectedGraph);
    // if (coloring.empty())
    //     cout << "Граф не является двудольным." << endl;
    // else {
    //     cout << "Граф является двудольным. Раскраска вершин:" << endl;
    //     for (const auto& pair : coloring)
    //         cout << pair.first << ": " << pair.second << endl;
    // }



    // Graph_ml orderedGraph(6, true);
    // orderedGraph.addEdge(0, 1, 10);
    // orderedGraph.addEdge(0, 2, 3);
    // orderedGraph.addEdge(0, 3, 1);
    // orderedGraph.addEdge(1, 5, 2);
    // orderedGraph.addEdge(2, 4, 1);
    // orderedGraph.addEdge(3, 2, 1);
    // orderedGraph.addEdge(3, 4, 7);
    // orderedGraph.addEdge(4, 5, 3);

    // cout << "Исходная матрица смежности графа:\n";
    // orderedGraph.printGraphMatrix();

    // vector<vector<int>> shortestPaths = floydWarshall(orderedGraph);
    // cout << "\nМатрица кратчайших путей между всеми парами вершин:\n";
    // printMatrix(shortestPaths);

    // cout << "Новая матрица смежности графа:\n";
    // orderedGraph.printGraphMatrix();



    // int numVertices = 5;
    // Graph_ml graph(numVertices, false);

    // graph.addEdge(0, 1, 4);
    // graph.addEdge(0, 2, 1);
    // graph.addEdge(1, 2, 2);
    // graph.addEdge(1, 3, 5);
    // graph.addEdge(2, 3, 2);
    // graph.addEdge(2, 4, 4);
    // graph.addEdge(3, 4, 3);

    // int startVertex = 3;
    // vector<int> distances = dijkstra(graph, startVertex);

    // cout << "Минимальные дистанции от вершины " << startVertex << ":\n";
    // for (int i = 0; i < numVertices; ++i) {
    //     cout << "К вершине " << i << ": " << distances[i] << "\n";
    // }



    // Graph_ml graph(4, false);

    // graph.addEdge(0, 1, 10);
    // graph.addEdge(0, 2, 6);
    // graph.addEdge(0, 3, 5);
    // graph.addEdge(1, 3, 15);
    // graph.addEdge(2, 3, 4);

    // Graph_ml mst = kruskalMST(graph);

    // cout << "Минимальное островное дерево:" << endl;
    // mst.printGraphMatrix();



    // Graph_ml graph(6, true); 

    // graph.addEdge(0, 1, 16);
    // graph.addEdge(0, 2, 13);
    // graph.addEdge(1, 2, 10);
    // graph.addEdge(1, 3, 12);
    // graph.addEdge(2, 1, 4);
    // graph.addEdge(2, 4, 14);
    // graph.addEdge(3, 2, 9);
    // graph.addEdge(3, 5, 20);
    // graph.addEdge(4, 3, 7);
    // graph.addEdge(4, 5, 4);

    // int source = 0;
    // int sink = 5;

    // int maxFlow = fordFulkerson(graph, source, sink);

    // cout << "Максимальный поток из истока " << source << " в сток " << sink << " равен: " << maxFlow << endl;



    // Graph_ml graph(5, true);
    // graph.addEdge(0, 1);
    // graph.addEdge(0, 3);
    // graph.addEdge(1, 2);
    // graph.addEdge(1, 3);
    // graph.addEdge(1, 4);
    // graph.addEdge(2, 3);
    // graph.addEdge(2, 4);

    // vector<int> topoSorted = topologicalSort(graph);

    // cout << "Топологический порядок:";
    // for (int v : topoSorted) {
    //     cout << " " << v;
    // }
    // cout << endl;



    // Graph_ml graph(4, false);

    // graph.addEdge(0, 1);
    // graph.addEdge(0, 2);
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);

    // vector<pair<int, int>> maxMatching = hopcroftKarp(graph);

    // cout << "Максимальное паросочетание:" << endl;
    // for (auto& edge : maxMatching) {
    //     cout << edge.first << " - " << edge.second << endl;
    // }



    
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


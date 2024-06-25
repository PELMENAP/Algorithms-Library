#include <bits/stdc++.h>

namespace graph
{
    class Graph {
    private:
        unordered_map<int, vector<int>> adjList;
        vector<vector<int>> adjMatrix;
        int numVertices;
        bool isDirected;

    public:
        Graph(int vertices, bool directed) : numVertices(vertices), isDirected(directed);

        Graph(const unordered_map<int, vector<int>>& list, bool directed);

        Graph(const vector<vector<int>>& matrix, bool directed);

        Graph(const Graph& other) : adjList(other.adjList), adjMatrix(other.adjMatrix), numVertices(other.numVertices), isDirected(other.isDirected);

        void addEdge(int u, int v);

        unordered_map<int, vector<int>> getGraphList() const;

        vector<vector<int>> getGraphMatrix() const;

        void printGraphList() const;

        void printGraphMatrix() const;
    };
}
#include <bits/stdc++.h>

namespace graph
{
    Graph::Graph(int vertices, bool directed) : numVertices(vertices), isDirected(directed) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        for (int i = 0; i < vertices; ++i) {
            adjList[i] = vector<int>();
        }
    }

    Graph::Graph(const unordered_map<int, vector<int>>& list, bool directed) 
        : adjList(list), isDirected(directed) {
        numVertices = list.size();
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (const auto& pair : list) {
            for (const auto& vertex : pair.second) {
                adjMatrix[pair.first][vertex] = 1;
            }
        }
    }

    Graph::Graph(const vector<vector<int>>& matrix, bool directed) 
        : adjMatrix(matrix), isDirected(directed) {
        numVertices = matrix.size();
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (matrix[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }
    }

    void Graph::addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    unordered_map<int, vector<int>> Graph::getGraphList() const {
        return adjList;
    }

    vector<vector<int>> Graph::getGraphMatrix() const {
        return adjMatrix;
    }

    void Graph::printGraphList() const {
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (const auto& vertex : pair.second) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    void Graph::printGraphMatrix() const {
        for (const auto& row : adjMatrix) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
}
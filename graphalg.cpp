#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>

#include "graphalg.hpp"

using namespace std;

namespace graphalgs
{
    Graph_ml::Graph_ml(int vertices, bool directed) : numVertices(vertices), isDirected(directed) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        for (int i = 0; i < vertices; ++i) {
            adjList[i] = vector<int>();
        }
    }

    Graph_ml::Graph_ml(const unordered_map<int, vector<int>>& list, bool directed) : adjList(list), isDirected(directed) {
        numVertices = list.size();
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (const auto& pair : list) {
            for (const auto& vertex : pair.second) {
                adjMatrix[pair.first][vertex] = 1;
            }
        }
    }

    Graph_ml::Graph_ml(const vector<vector<int>>& matrix, bool directed) 
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

    void Graph_ml::addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    unordered_map<int, vector<int>> Graph_ml::getGraphList() const {
        return adjList;
    }

    vector<vector<int>> Graph_ml::getGraphMatrix() const {
        return adjMatrix;
    }

    void Graph_ml::printGraphList() const {
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (const auto& vertex : pair.second) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    void Graph_ml::printGraphMatrix() const {
        for (const auto& row : adjMatrix) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
}
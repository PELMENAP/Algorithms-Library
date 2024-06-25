#include <stdio.h>
#include <stdlib.h>

static int* generateRandomArrayMassive(size_t size, size_t maxValue)
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    srand(now.tv_nsec);
    int* arr = (int *)malloc(sizeof(int)*size);
    for (size_t i = 0; i < size; i++)
        arr[i] = rand()%maxValue;
    return arr;
}


static void printArray(int *arr, size_t n)
{
    for (size_t i=0; i<n; ++i){
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
    printf("\n");
}

class Graph {
private:
    unordered_map<int, vector<int>> adjList;
    vector<vector<int>> adjMatrix;
    int numVertices;
    bool isDirected;

public:
    Graph(int vertices, bool directed) : numVertices(vertices), isDirected(directed) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        for (int i = 0; i < vertices; ++i) {
            adjList[i] = vector<int>();
        }
    }

    Graph(const unordered_map<int, vector<int>>& list, bool directed) 
        : adjList(list), isDirected(directed) {
        numVertices = list.size();
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (const auto& pair : list) {
            for (const auto& vertex : pair.second) {
                adjMatrix[pair.first][vertex] = 1;
            }
        }
    }

    Graph(const vector<vector<int>>& matrix, bool directed) 
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

    Graph(const Graph& other) 
        : adjList(other.adjList), adjMatrix(other.adjMatrix), 
          numVertices(other.numVertices), isDirected(other.isDirected) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    unordered_map<int, vector<int>> getGraphList() const {
        return adjList;
    }

    vector<vector<int>> getGraphMatrix() const {
        return adjMatrix;
    }

    void printGraphList() const {
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (const auto& vertex : pair.second) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    void printGraphMatrix() const {
        for (const auto& row : adjMatrix) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};
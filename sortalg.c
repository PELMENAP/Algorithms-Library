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

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjMatrix[u][v] = 1;
    if (!isDirected) {
        adjList[v].push_back(u);
        adjMatrix[v][u] = 1;
    }
}

Graph::unordered_map<int, vector<int>> getGraphList() const {
    return adjList;
}

Graph::vector<vector<int>> getGraphMatrix() const {
    return adjMatrix;
}

Graph::void printGraphList() const {
    for (const auto& pair : adjList) {
        cout << pair.first << ": ";
        for (const auto& vertex : pair.second) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

Graph::void printGraphMatrix() const {
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <climits>
#include <limits>

using namespace std;

namespace graphalgs
{
    void printMatrix(const vector<vector<int>>& matrix);

    class Graph_ml 
    {
        private:
            unordered_map<int, vector<int>> adjList;
            vector<vector<int>> adjMatrix;
            int numVertices;
            bool isDirected;

            void DFSUtil(int v, set<int>& visited, vector<int>& component) const;  
            void BFSUtil(int startVertex, set<int>& visited, vector<int>& result) const;

        public:
            Graph_ml(int vertices, bool directed);
            Graph_ml(const unordered_map<int, vector<int>>& list, bool directed);
            Graph_ml(const vector<vector<int>>& matrix, bool directed);
            Graph_ml(const Graph_ml& other);

            void addEdge(int u, int v);
            void addEdge(int u, int v, int weight);

            unordered_map<int, vector<int>> getGraphList() const;
            vector<vector<int>> getGraphMatrix() const;
            int getNumVertices() const ;

            void printGraphList() const;
            void printGraphMatrix() const;

            vector<int> DFS(int startVertex) const;
            vector<int> BFS(int startVertex) const;

            vector<int> DFSIterative(int startVertex) const;
            vector<int> BFSIterative(int startVertex) const;
    };

    vector<int> connectedComponents(const Graph_ml& graph);

    unordered_map<int, int> checkBipartite(const Graph_ml& graph);

    vector<vector<int>> floydWarshall(const Graph_ml& graph);

    vector<int> dijkstra(const Graph_ml& graph, int startVertex);

    Graph_ml kruskalMST(const Graph_ml &graph);

    int fordFulkerson(const Graph_ml& graph, int source, int sink);

    vector<int> topologicalSort(const Graph_ml& graph);

    vector<pair<int, int>> hopcroftKarp(const Graph_ml& graph);
}
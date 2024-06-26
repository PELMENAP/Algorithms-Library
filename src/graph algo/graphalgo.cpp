#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>


#include "graphalgo.hpp"

using namespace std;

namespace graphalgs
{
    void printMatrix(const vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    Graph_ml::Graph_ml(int vertices, bool directed) : numVertices(vertices), isDirected(directed) 
    {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        for (int i = 0; i < vertices; ++i) 
        {
            adjList[i] = vector<int>();
        }
    }

    Graph_ml::Graph_ml(const unordered_map<int, vector<int>>& list, bool directed) : adjList(list), isDirected(directed) 
    {
        numVertices = list.size();
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (const auto& pair : list) 
        {
            for (const auto& vertex : pair.second) 
            {
                adjMatrix[pair.first][vertex] = 1;
            }
        }
    }

    Graph_ml::Graph_ml(const vector<vector<int>>& matrix, bool directed) : adjMatrix(matrix), isDirected(directed) 
    {
        numVertices = matrix.size();
        for (int i = 0; i < numVertices; ++i) 
        {
            for (int j = 0; j < numVertices; ++j) 
            {
                if (matrix[i][j] == 1) 
                {
                    adjList[i].push_back(j);
                }
            }
        }
    }

    void Graph_ml::addEdge(int u, int v) 
    {
        if(u + 1 > numVertices || v + 1 > numVertices) return;
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
        if (!isDirected) 
        {
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    void Graph_ml::addEdge(int u, int v, int weight) 
    {
        if(u + 1 > numVertices || v + 1 > numVertices) return;
        adjList[u].push_back(v);
        adjMatrix[u][v] = weight;
        if (!isDirected) 
        {
            adjList[v].push_back(u);
            adjMatrix[v][u] = weight;
        }
    }

    unordered_map<int, vector<int>> Graph_ml::getGraphList() const 
    {
        return adjList;
    }

    vector<vector<int>> Graph_ml::getGraphMatrix() const 
    {
        return adjMatrix;
    }

    int Graph_ml::getNumVertices() const 
    {
        return numVertices;
    }

    void Graph_ml::printGraphList() const 
    {
        for (const auto& pair : adjList) 
        {
            cout << pair.first << ": ";
            for (const auto& vertex : pair.second) 
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    void Graph_ml::printGraphMatrix() const 
    {
        for (const auto& row : adjMatrix) 
        {
            for (const auto& val : row) 
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void Graph_ml::DFSUtil(int v, set<int>& visited, vector<int>& component) const 
    {
        visited.insert(v);
        component.push_back(v);

        for (int neighbor : adjList.at(v)) 
        {
            if (visited.find(neighbor) == visited.end()) 
            {
                DFSUtil(neighbor, visited, component);
            }
        }
    }  

    void Graph_ml::BFSUtil(int startVertex, set<int>& visited, vector<int>& result) const 
    {
        queue<int> queue;
        queue.push(startVertex);
        visited.insert(startVertex);

        while (!queue.empty()) 
        {
            int vertex = queue.front();
            queue.pop();
            result.push_back(vertex);

            for (int neighbor : adjList.at(vertex)) 
            {
                if (visited.find(neighbor) == visited.end()) 
                {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
    }

    vector<int> Graph_ml::DFS(int startVertex) const 
    {
        set<int> visited;
        vector<int> result;

        DFSUtil(startVertex, visited, result);

        return result;
    }

    vector<int> Graph_ml::BFS(int startVertex) const 
    {
        set<int> visited;
        vector<int> result;
        BFSUtil(startVertex, visited, result);
        return result;
    }

    vector<int> Graph_ml::DFSIterative(int startVertex) const 
    {
        set<int> visited;
        vector<int> result;
        stack<int> stack;

        stack.push(startVertex);

        while (!stack.empty()) 
        {
            int vertex = stack.top();
            stack.pop();

            if (visited.find(vertex) == visited.end()) 
            {
                visited.insert(vertex);
                result.push_back(vertex);

                for (auto it = adjList.at(vertex).rbegin(); it != adjList.at(vertex).rend(); ++it) 
                {
                    if (visited.find(*it) == visited.end()) 
                    {
                        stack.push(*it);
                    }
                }
            }
        }
        return result;
    }

    vector<int> Graph_ml::BFSIterative(int startVertex) const 
    {
        set<int> visited;
        vector<int> result;
        queue<int> queue;
        queue.push(startVertex);
        visited.insert(startVertex);

        while (!queue.empty()) 
        {
            int vertex = queue.front();
            queue.pop();
            result.push_back(vertex);

            for (int neighbor : adjList.at(vertex)) 
            {
                if (visited.find(neighbor) == visited.end()) 
                {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        return result;
    }

    vector<int> connectedComponents(const Graph_ml& graph)
    {
        int numVertices = graph.getNumVertices();
        unordered_map<int, vector<int>> adjList = graph.getGraphList();

        set<int> visited;
        vector<int> componentCount(numVertices, -1);
        int componentId = 0;

        for (const auto& pair : adjList) 
        {
            int vertex = pair.first;
            if (visited.find(vertex) == visited.end()) 
            {
                vector<int> component = graph.DFSIterative(vertex);
                for (int v : component) 
                {
                    componentCount[v] = componentId;
                    visited.insert(v);
                }
                componentId++;
            }
        }

        return componentCount;
    }

    unordered_map<int, int> checkBipartite(const Graph_ml& graph) 
    {
        int numVertices = graph.getNumVertices();
        unordered_map<int, int> colors;
        queue<int> q;

        for (int i = 0; i < numVertices; ++i) 
        {
            if (colors.find(i) == colors.end()) 
            {
                q.push(i);
                colors[i] = 1;

                while (!q.empty()) 
                {
                    int u = q.front();
                    q.pop();

                    vector<int> list = graph.getGraphList().at(u);
                    for (int v : list) 
                    {
                        if (colors.find(v) == colors.end()) 
                        {
                            colors[v] = (colors[u] == 1) ? 2 : 1;
                            q.push(v);
                        } else if (colors[v] == colors[u]) 
                        {
                            colors.clear();
                            return colors;
                        }
                    }
                }
            }
        }

        return colors;
    }

    vector<vector<int>> floydWarshall(const Graph_ml& graph) 
    {
        int n = graph.getNumVertices();
        vector<vector<int>> dist = graph.getGraphMatrix();

        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (dist[i][j] == 0 && i != j) 
                {
                    dist[i][j] = INT_MAX;
                }
            }
        }

        for (int k = 0; k < n; ++k) 
        {
            for (int i = 0; i < n; ++i) 
            {
                if (dist[i][k] == INT_MAX) continue;
                for (int j = 0; j < n; ++j) 
                {
                    if (dist[k][j] == INT_MAX) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) 
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }

    vector<int> dijkstra(const Graph_ml& graph, int startVertex) 
    {
        int numVertices = graph.getNumVertices();
        vector<vector<int>> adjMatrix = graph.getGraphMatrix();

        vector<int> distances(numVertices, numeric_limits<int>::max());
        distances[startVertex] = 0;

        vector<bool> visited(numVertices, false);

        for (int count = 0; count < numVertices - 1; ++count) 
        {
            int minDistance = numeric_limits<int>::max();
            int minVertex;

            for (int v = 0; v < numVertices; ++v) 
            {
                if (!visited[v] && distances[v] <= minDistance) 
                {
                    minDistance = distances[v];
                    minVertex = v;
                }
            }

            visited[minVertex] = true;

            for (int v = 0; v < numVertices; ++v) 
            {
                if (!visited[v] && adjMatrix[minVertex][v] != 0 &&
                    distances[minVertex] != numeric_limits<int>::max() &&
                    distances[minVertex] + adjMatrix[minVertex][v] < distances[v]) 
                    distances[v] = distances[minVertex] + adjMatrix[minVertex][v];
            }
        }

        return distances;
    }

    int find(vector<int> &parent, int i) 
    {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int> &parent, int x, int y) 
    {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        parent[rootX] = rootY;
    }

    Graph_ml kruskalMST(const Graph_ml &graph) {
        int V = graph.getNumVertices();
        vector<vector<int>> adjMatrix = graph.getGraphMatrix();

        vector<Edge> edges;
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                if (adjMatrix[i][j] != 0) {
                    edges.push_back(Edge(i, j, adjMatrix[i][j]));
                }
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V, -1);

        Graph_ml mst(V, false); 
        int edgeCount = 0;
        int index = 0;
        while (edgeCount < V - 1 && index < edges.size()) {
            Edge next_edge = edges[index++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);
            if (x != y) {
                mst.addEdge(next_edge.src, next_edge.dest, next_edge.weight);
                Union(parent, x, y);
                edgeCount++;
            }
        }
        return mst;
    }

    int fordFulkerson(const Graph_ml& graph, int source, int sink) 
    { 
        auto adjMatrix = graph.getGraphMatrix();
        int numVertices = graph.getNumVertices();

        int maxFlow = 0;

        while (true) {
            vector<int> parent(numVertices, -1);
            vector<bool> visited(numVertices, false);

            queue<int> q;
            q.push(source);
            visited[source] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < numVertices; ++v) {
                    if (!visited[v] && adjMatrix[u][v] > 0) {
                        q.push(v);
                        visited[v] = true;
                        parent[v] = u;
                    }
                }
            }

            if (visited[sink]) {
                int pathFlow = numeric_limits<int>::max();
                for (int v = sink; v != source; v = parent[v]) {
                    int u = parent[v];
                    pathFlow = min(pathFlow, adjMatrix[u][v]);
                }

                for (int v = sink; v != source; v = parent[v]) {
                    int u = parent[v];
                adjMatrix[u][v] -= pathFlow;
                adjMatrix[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        } else {
            break;
        }
        }
        return maxFlow;
    }

    vector<int> topologicalSort(const Graph_ml& graph) 
    {
        unordered_map<int, vector<int>> adjList = graph.getGraphList();
        int numVertices = graph.getNumVertices();

        vector<int> topoOrder;
        vector<bool> visited(numVertices, false);
        stack<int> stk;

        function<void(int)> dfs = [&](int v) 
        {
            visited[v] = true;
            for (int neighbor : adjList[v]) 
            {
                if (!visited[neighbor]) 
                {
                    dfs(neighbor);
                }
            }
            stk.push(v);
        };

        for (int i = 0; i < numVertices; ++i) 
        {
            if (!visited[i]) 
            {
                dfs(i);
            }
        }

        while (!stk.empty()) 
        {
            topoOrder.push_back(stk.top());
            stk.pop();
        }

        return topoOrder;
    }

    bool bfs(const Graph_ml& graph, int u, unordered_map<int, vector<int>>& adjList, vector<int>& pairU, vector<int>& pairV, vector<int>& dist) 
    {
        queue<int> q;
        for (int v : adjList[u]) 
        {
            if (pairV[v] == -1) 
            {
                dist[v] = 0;
                q.push(v);
            }
        }
        bool found = false;
        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();
            for (int u : adjList[v]) 
            {
                int uPrime = pairU[u];
                if (uPrime == -1) 
                {
                    found = true;
                } else if (dist[uPrime] == -1) 
                {
                    dist[uPrime] = dist[v] + 1;
                    q.push(uPrime);
                }
            }
        }
        return found;
    }

    bool dfs(const Graph_ml& graph, int u, unordered_map<int, vector<int>>& adjList, vector<int>& pairU, vector<int>& pairV, vector<int>& dist) 
    {
        for (int v : adjList[u]) 
        {
            int uPrime = pairU[u];
            if (v == uPrime) 
            {
                continue;
            }
            int vPrime = pairV[v];
            if (vPrime == -1 || (dist[vPrime] == dist[u] + 1 && dfs(graph, vPrime, adjList, pairU, pairV, dist))) 
            {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    vector<pair<int, int>> hopcroftKarp(const Graph_ml& graph) 
    {
        unordered_map<int, vector<int>> adjList = graph.getGraphList();
        int numVertices = graph.getNumVertices();

        vector<int> pairU(numVertices, -1);
        vector<int> pairV(numVertices, -1);
        vector<int> dist(numVertices);

        vector<pair<int, int>> maxMatching;

        while (bfs(graph, 0, adjList, pairU, pairV, dist)) 
        {
            for (int u = 0; u < numVertices; ++u) 
            { 
                if (pairU[u] == -1 && dfs(graph, u, adjList, pairU, pairV, dist)) 
                {
                    maxMatching.emplace_back(u, pairU[u]);
                }
            }
        }

        return maxMatching;
    }

}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
using namespace std;

namespace graphalgs
{
    class Graph_ml 
    {
        private:
            unordered_map<int, vector<int>> adjList;
            vector<vector<int>> adjMatrix;
            int numVertices;
            bool isDirected;

            void DFSUtil(int v, set<int>& visited, vector<int>& component) const {
                visited.insert(v);
                component.push_back(v);

                for (int neighbor : adjList.at(v)) {
                    if (visited.find(neighbor) == visited.end()) {
                        DFSUtil(neighbor, visited, component);
                    }
                }
            }       

        public:
            Graph_ml(int vertices, bool directed);

            Graph_ml(const unordered_map<int, vector<int>>& list, bool directed);

            Graph_ml(const vector<vector<int>>& matrix, bool directed);

            Graph_ml(const Graph_ml& other);

            void addEdge(int u, int v);

            unordered_map<int, vector<int>> getGraphList() const;

            vector<vector<int>> getGraphMatrix() const;

            void printGraphList() const;

            void printGraphMatrix() const;

            vector<int> DFS(int startVertex) const 
            {
                set<int> visited;
                vector<int> result;

                DFSUtil(startVertex, visited, result);

                return result;
            }

            vector<int> DFSIterative(int startVertex) const {
                set<int> visited;
                vector<int> result;
                stack<int> stack;

                stack.push(startVertex);

                while (!stack.empty()) {
                    int vertex = stack.top();
                    stack.pop();

                    if (visited.find(vertex) == visited.end()) {
                        visited.insert(vertex);
                        result.push_back(vertex);

                        for (auto it = adjList.at(vertex).rbegin(); it != adjList.at(vertex).rend(); ++it) {
                            if (visited.find(*it) == visited.end()) {
                                stack.push(*it);
                            }
                        }
                    }
                }
                return result;
            }
            
    };
}
// C++ program for Topological Sorting using Kahn's Algorithm (BFS)

class Solution {
public:
    /**
     * @brief Performs topological sorting of a directed acyclic graph (DAG).
     *
     * @param V Number of vertices in the graph.
     * @param adj Adjacency list representing the graph.
     * @return A vector containing the topological order of vertices.
     */
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);  // Array to store in-degrees of all vertices

        // Step 1: Compute in-degrees of all vertices
        for (int i = 0; i < V; i++) {
            for (auto &it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;

        // Step 2: Enqueue vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        // Step 3: Process nodes using BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            // Reduce in-degree of neighboring nodes
            for (auto &it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topoOrder;  // Contains topological ordering of nodes
    }
};



📊 Time and Space Complexity:
Time Complexity: O(V + E)

Visiting each node and traversing each edge once.

Space Complexity: O(V)

For inDegree[], queue, and result vector.


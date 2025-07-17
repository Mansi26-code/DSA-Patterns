// C++ program to detect a cycle in a directed graph using Kahn's Algorithm (BFS)

class Solution {
public:
    /**
     * @brief Checks if there is a cycle in the directed graph using Kahn's Algorithm.
     * 
     * @param N Number of vertices in the graph.
     * @param adj Adjacency list representing the graph.
     * @return true if there is a cycle, false otherwise.
     */
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> inDegree(N, 0); // Stores in-degrees of all vertices

        // Step 1: Compute in-degree for each node
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;

        // Step 2: Enqueue all nodes with in-degree 0
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        int count = 0; // Count of nodes processed in topological order

        // Step 3: Perform BFS (Kahn’s Algorithm)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Reduce in-degree of adjacent nodes
            for (auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: If all nodes were processed, no cycle; otherwise, cycle exists
        return count != N;
    }
};
📊 Time and Space Complexity:
Time Complexity: O(V + E)

Visiting all vertices and traversing all edges once.

Space Complexity: O(V)

For inDegree[] array and queue used in BFS.


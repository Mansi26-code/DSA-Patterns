// ✅ Time Complexity: O(V + E)
//    - V = number of nodes (graph.size())
//    - E = total number of directed edges in the graph
//
// ✅ Space Complexity: O(V + E)
//    - Adjacency list (reversed graph): O(E)
//    - In-degree array, queue, and result vector: O(V)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Step 1: Reverse the graph
        // If original graph has edge u → v, reversed graph has edge v → u
        vector<vector<int>> adj(V); // reversed adjacency list
        for (int i = 0; i < V; i++) {
            for (auto &it : graph[i]) {
                adj[it].push_back(i); // reverse the edge
            }
        }

        // Step 2: Build the in-degree array for reversed graph
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto &it : adj[i]) {
                inDegree[it]++;
            }
        }

        // Step 3: Initialize queue with nodes having in-degree 0
        // These nodes are terminal nodes in the original graph
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Perform Kahn’s Algorithm (Topological Sort)
        vector<int> res; // to store safe nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node); // this node is safe

            // Reduce in-degree of all neighbors in reversed graph
            for (auto &it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Step 5: Sort the result as required in ascending order
        sort(res.begin(), res.end());

        return res; // list of all safe nodes
    }
};

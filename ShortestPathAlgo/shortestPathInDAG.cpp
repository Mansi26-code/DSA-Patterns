class Solution {
public:
    // 🔁 Recursive function to perform topological sort
    // Pushes the node into stack after visiting all its neighbors (DFS style)
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;  // Mark the current node as visited

        for (auto& it : adj[node]) {
            int v = it.first;
            // If the neighbor has not been visited, call DFS recursively
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }

        // Push current node to stack after visiting all its children
        st.push(node);
    }

    // 🛣️ Function to find shortest paths from node 0 to all other nodes in a DAG
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // 📌 Step 1: Convert edge list into an adjacency list with weights
        vector<pair<int, int>> adj[N];  // Each pair: (destination, weight)
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];  // From node
            int v = edges[i][1];  // To node
            int wt = edges[i][2]; // Weight of the edge
            adj[u].push_back({v, wt});
        }

        // 📌 Step 2: Perform topological sort
        vector<int> vis(N, 0);     // Visited array for DFS
        stack<int> st;             // Stack to store topological order
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // 📌 Step 3: Initialize distances from source (0) to all other nodes
        vector<int> dist(N, INT_MAX);  // Initially all distances are infinity
        dist[0] = 0;                   // Distance to source itself is 0

        // 📌 Step 4: Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // Only relax edges if the current node is reachable
            if (dist[node] != INT_MAX) {
                for (auto& it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    // Relaxation step: update distance if shorter path is found
                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }

        // 📌 Step 5: Convert unreachable node distances (INT_MAX) to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        // 📌 Final result: shortest distances from source node 0 to all nodes
        return dist;
    }
};


// Time Complexity:O(N + M), where N is the number of nodes and M is the number of edges, due to topological sort and shortest path calculation.
// Space Complexity:O(N), where N is the number of nodes, primarily due to the visited array, stack, and distance array.
class Solution {
public:
    // DFS function to visit all nodes in a connected component
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;  // Mark current node as visited

        // Visit all neighbors of the current node
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(); // Number of nodes
        vector<vector<int>> adj(V); // Adjacency list

        // 🔁 Convert Adjacency Matrix to Adjacency List
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If there is an edge and not a self-loop
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0); // Visited array
        int count = 0; // Count of connected components (or provinces)

        // 🔁 Run DFS for every unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;                // New component found
                dfs(i, adj, vis);       // Visit entire component
            }
        }

        return count;
    }
};


//tc=✅ O(V^2) (since max edges = V², and matrix traversal dominates)

//sc= O(V + E) auxiliary space + O(V^2) input space (matrix)
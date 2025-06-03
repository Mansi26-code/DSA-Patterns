class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();                // Number of vertices
        vector<int> vis(n, 0);             // Visited array to track visited nodes
        queue<int> q;                      // Queue for BFS
        vector<int> bfs;                   // Result vector to store BFS traversal

        vis[0] = 1;                        // Mark starting node (0) as visited
        q.push(0);                         // Start BFS from node 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);          // Add current node to result

            for (auto &it : adj[node]) {  // Traverse all adjacent nodes
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};


📊 Time Complexity
O(N + E)
Where N is the number of vertices and E is the number of edges.
Every node and edge is visited once.

📦 Space Complexity
O(N) for visited array.

O(N) for queue in worst case.

O(N) for result vector.
So, total is O(N) auxiliary space.
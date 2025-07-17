class Solution {
  public:

   void dfs(int node, vector<vector<int>>& edges, vector<vector<int>>& adj, vector<int>& vis) {
      vis[node] = 1;

      for (auto it : adj[node]) {
          if (!vis[it]) {
              dfs(it, edges, adj, vis);
          }
      }
   }

   int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        // Creating adjacency list from edge list
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // undirected graph
        }

        vector<int> vis(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, edges, adj, vis);
            }
        }

        return count;
    }
};
✅ Total Space Complexity = O(V + E)

✅ Total Time Complexity = O(V + E)


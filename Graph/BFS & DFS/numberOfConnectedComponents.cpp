class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {
        vis[node] = 1;
        for (auto& it : adj[node]) {
            if (!vis[it]) {

                dfs(adj, it, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        vector<int> vis(n, 0);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(adj, i, vis);
            }
        }
        return count;
    }
};
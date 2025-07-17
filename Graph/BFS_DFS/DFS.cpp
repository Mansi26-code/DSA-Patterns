class Solution {
public:

    // DFS helper function
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res) {
        vis[node] = 1;            // mark current node as visited
        res.push_back(node);      // add node to result

        // explore all unvisited adjacent nodes
        for (auto &it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, res);
            }
        }
    }

    // DFS traversal from node 0
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();             // number of nodes
        vector<int> vis(n, 0);          // visited array
        vector<int> res;                // to store the DFS traversal

        dfs(0, adj, vis, res);          // call dfs starting from node 0
        return res;
    }
};



⏱️ Time Complexity:
O(N + E)

N = number of nodes

E = number of edges



💾 Space Complexity:
O(N)
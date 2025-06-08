class Solution {
   public:
    bool dfs(int node, int col, vector<int> color, vector<int> adj[]) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, adj) == false) return false;
            }

            else if (color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) return false;
            }
        }
        return true;
    }
};



Time Complexity:O(V+E) due to the Depth-First Search traversal of the graph's vertices and edges, plus O(V) for the initial loop.
Space Complexity:O(V) for the color array and the recursion stack during DFS, in the worst-case scenario.
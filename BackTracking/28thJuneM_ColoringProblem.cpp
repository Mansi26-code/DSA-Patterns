// Problem: You have an undirected graph with n nodes.

// You must color each node using at most m colors, so that no two adjacent nodes have the same color.

// Return true if it’s possible to do so, otherwise false.



class Solution {
public:
    // Helper function to check if it is safe to color the current node with 'col'
    bool isSafe(int node, vector<vector<int>>& adj, int col, vector<int>& colors) {
        // Check all adjacent nodes of 'node'
        for (int i = 0; i < adj[node].size(); i++) {
            int adjacentNode = adj[node][i];
            // If adjacent node already has the same color, it's not safe
            if (colors[adjacentNode] == col) {
                return false;
            }
        }
        // No adjacent node has the same color
        return true;
    }

    // Recursive function to try coloring the graph
    bool solve(int col, vector<int>& colors, vector<vector<int>>& adj, int node, int m, int n) {
        // Base Case:
        // If we have colored all nodes successfully, return true
        if (node == n) {
            return true;
        }

        // Try all colors from 1 to m for the current node
        for (int i = 1; i <= m; i++) {
            // Check if it's safe to color this node with color 'i'
            if (isSafe(node, adj, i, colors)) {
                // Assign the color
                colors[node] = i;

                // Recurse to the next node
                if (solve(col, colors, adj, node + 1, m, n)) {
                    return true;
                }

                // Backtrack: Remove the color if it leads to no solution ahead
                colors[node] = 0;
            }
        }

        // If no color can be assigned to this node, return false
        return false;
    }

    // Main function to start the coloring process
    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
        // Convert edge list to adjacency list for easy traversal
        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Initialize colors array: colors[i] = 0 means uncolored
        vector<int> colors(n, 0);

        // Start solving from node 0
        return solve(0, colors, adj, 0, m, n);
    }
};


Time Complexity:The time complexity is O(m^n), where m is the number of colors and n is the number of nodes, due to the recursive calls in the solve function.
Space Complexity:The space complexity is O(n), primarily due to the 'colors' vector and the depth of the recursion stack in the worst case.





// You are given a directed graph and a source and destination.
// Return true if every path starting from source ends at destination, with no cycles and no other terminal nodes.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * DFS helper function to validate whether all paths from `node`
     * eventually lead to the `destination`.
     *
     * visited[node] states:
     * 0 = unvisited
     * 1 = visiting (currently in recursion stack)
     * 2 = safe (already verified to lead to destination)
     */
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int destination) {
        // If it's a terminal node (no outgoing edges)
        if (adj[node].empty()) {
            return node == destination; // Must end at destination
        }

        if (visited[node] == 1) return false; // Detected a cycle
        if (visited[node] == 2) return true;  // Already verified as safe

        visited[node] = 1; // Mark as visiting (to detect cycles)

        // Recur for all adjacent nodes
        for (int next : adj[node]) {
            if (!dfs(next, adj, visited, destination)) {
                return false;
            }
        }

        visited[node] = 2; // Mark as safe
        return true;
    }

    /*
     * Main function to determine whether all paths from source
     * eventually lead to the destination.
     */
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        // Build adjacency list from edge list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(n, 0); // 0 = unvisited
        return dfs(source, adj, visited, destination);
    }
};

// Sample usage
int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {2,3}};
    int source = 0, destination = 3;

    bool result = sol.leadsToDestination(n, edges, source, destination);
    cout << (result ? "true" : "false") << endl;

    return 0;
}


// Time Complexity: O(N + E), where N = number of nodes, E = number of edges (standard DFS traversal).

// Space Complexity: O(N) for visited array and recursion stack.


// C++ program to detect cycle in an undirected graph using DFS
class Solution {
public:

    /**
     * @brief Depth-First Search to detect a cycle in an undirected graph.
     * 
     * @param node Current node being visited.
     * @param parent The node from which the current node was visited.
     * @param vis Visited array to keep track of visited nodes.
     * @param adj Adjacency list of the graph.
     * @return true if a cycle is found, false otherwise.
     */
    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;  // Mark the current node as visited

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            // If the adjacent node has not been visited, recurse on it
            if (!vis[it]) {
                if (dfs(it, node, vis, adj))
                    return true;
            }
            // If the adjacent node is visited and not parent, then cycle exists
            else if (it != parent) {
                return true;
            }
        }

        return false; // No cycle found in this DFS path
    }

    /**
     * @brief Function to check whether a cycle exists in an undirected graph.
     * 
     * @param V Number of vertices in the graph.
     * @param adj Adjacency list representing the graph.
     * @return true if the graph contains a cycle, false otherwise.
     */
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // Initialize visited array

        // Check for cycle in each connected component
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }

        return false; // No cycle found in any component
    }
};


📊 Time and Space Complexity:
Time Complexity: O(V + E)

Each vertex and edge is visited once in DFS.

Space Complexity: O(V)

Due to the visited array and the recursion stack in the worst case.
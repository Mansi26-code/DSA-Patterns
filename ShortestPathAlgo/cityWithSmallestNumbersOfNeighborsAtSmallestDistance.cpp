class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {

        // Adjacency list to store the graph as: node -> list of {neighbor, weight}
        vector<vector<pair<int,int>>> adj(n);  

        // Building the adjacency list from edges
        for(auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});  // Undirected edge
            adj[it[1]].push_back({it[0], it[2]});
        }

        int city = -1;           // To store final answer (city index)
        int minReachable = n;    // Minimum number of reachable cities within threshold

        // Try starting from every city (i)
        for(int i = 0; i < n; ++i) {

            // Distance array initialized with large value (infinity)
            vector<int> dist(n, 1e9);  
            dist[i] = 0;  // Distance to itself is zero

            // Queue for Dijkstra's algorithm: {current_node, current_cost}
            queue<pair<int,int>> q;
            q.push({i, 0});  

            // Dijkstra's/BFS-like loop
            while(!q.empty()) {
                auto front = q.front();
                int node = front.first;
                int cost = front.second;
                q.pop();

                // Visit all neighbors of current node
                for(auto &it : adj[node]) {
                    int neighbor = it.first;
                    int weight = it.second;

                    // If a shorter path to neighbor is found
                    if(cost + weight < dist[neighbor]) {
                        dist[neighbor] = cost + weight;
                        q.push({neighbor, dist[neighbor]});  // Push updated distance
                    }
                }
            }

            // Count how many cities are reachable within threshold distance
            int reachable = 0;
            for(int j = 0; j < n; ++j) {
                if(i != j && dist[j] <= distanceThreshold) {
                    reachable++;
                }
            }

            // Choose the city with:
            // - Fewer reachable cities
            // - If tie, choose city with greater index
            if(reachable <= minReachable) {
                minReachable = reachable;
                city = i;
            }
        }

        return city;  // Return the city with minimum reachable cities under threshold
    }
};


Time Complexity:O(n * (m + n) * log(n))
Space Complexity:O(n^2)
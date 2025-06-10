class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Step 1: Initialize distance array with "infinite" values
        vector<int> dist(V, 1e9);

        // Step 2: Min-heap (priority queue) to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 3: Distance from source to itself is 0
        dist[S] = 0;
        pq.push({0, S});

        // Step 4: Main loop of Dijkstra's algorithm
        while (!pq.empty()) {
            int distance = pq.top().first;  // current shortest distance
            int node = pq.top().second;     // current node being processed
            pq.pop();

            // Step 5: Explore all neighbors of the current node
            for (auto &it : adj[node]) {
                int adjNode = it[0];  // Neighbor node
                int wt = it[1];       // Weight of the edge to the neighbor

                // Step 6: Relaxation — update the shortest path if a better one is found
                if (distance + wt < dist[adjNode]) {
                    dist[adjNode] = distance + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Step 7: Final distance array from source node S
        return dist;
    }
};
Time Complexity:O((V+E)logV), 
Space Complexity:O(V)
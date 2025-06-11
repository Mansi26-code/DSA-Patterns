class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]}); // because it's undirected
        }

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for(auto &[adjNode, wt] : adj[node]) {
                if(d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if(d + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};

Time Complexity:O(E + VlogV), where E is the number of roads and V is the number of nodes, due to the priority queue operations and graph traversal.
Space Complexity:O(V + E), where V is the number of nodes for the distance and ways vectors, and E for the adjacency list.
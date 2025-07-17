class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[N];
        vector<int> indegree(N, 0);

        // Build adjacency list and indegree array
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            indegree[v]++;
        }

        // Kahn's algorithm queue
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Topological order vector
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto &it : adj[node]) {
                int v = it.first;
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Initialize distances
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Relax edges in topological order
        for (int i = 0; i < topo.size(); i++) {
            int node = topo[i];
            if (dist[node] != 1e9) {
                for (auto &it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Mark unreachable nodes as -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

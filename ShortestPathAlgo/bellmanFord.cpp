class Solution {
   public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> dis(V, 1e9);
        dis[S] = 0;

        for (int i = 0; i < V; i++) {
            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];

                if (dis[u] != 1e9 && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dis[u] != 1e9 && dis[u] + w < dis[v]) {
                return {-1};
            }
        }
        return dis;
    }
};
//to detect negative cycles
//tc= O(V*E) 
//sc=O(V)


class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K) {
        vector<pair<int,int>>adj[n];
        for(auto &it:flights)
        {
           adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}}); //stops,node, distance
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty())
        {
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();

            if(stops>K)
            continue;

            for(auto &iter:adj[node])
            {
                int adjNode=iter.first;
                int edw=iter.second;

                if(cost+edw<dist[adjNode] && stops<=K)
                {
                    dist[adjNode]=cost+edw;
                    q.push({stops+1,{adjNode,cost+edw}});
                }
            }

        }
        if(dist[dst]==1e9)
        return -1;

        return dist[dst];

    }
};
Time Complexity:O(E + (V+E)*K)
Space Complexity:O(V + E + K)

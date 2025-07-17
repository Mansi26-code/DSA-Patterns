class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
         
         priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
         
         vector<int>dist(V,1e9);
          dist[S] = 0;
         pq.push({0,S});
         while(!pq.empty())
         {
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();

            for(auto &it:adj[node])
            {
                int v=it[0];
                int wt=it[1];

                if(distance+wt<dist[v])
                {
                    dist[v]=distance+wt;
                    pq.push({dist[v],v});
                }
            }
         }
     
         return dist;
    }
};
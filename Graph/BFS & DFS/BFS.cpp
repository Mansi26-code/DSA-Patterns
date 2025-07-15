

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V=adj.size();
        vector<int>ans;
        vector<int>vis(V,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto &it:adj[node])
            { 
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
                
            }
        }
        return ans;
        
    }
};
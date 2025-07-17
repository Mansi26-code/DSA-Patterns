🕒 Time Complexity: O(V + E)
   - V = numCourses (nodes)
   - E = prerequisites (edges)

🗂️ Space Complexity: O(V + E)
   - Adjacency list: O(E)
   - In-degree array: O(V)
   - Queue and answer vector: O(V)



   class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        vector<int>inDegree(N);

vector<vector<int>>adj(N);
        
        for(auto &it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
           
        }
        for(int i=0;i<N;i++)
        {
            for(auto &it:adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;

        for(int i=0;i<N;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(auto &it:adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()==N)
        return ans;

        return {};
    }
};

Topo Sort 
Sbse pehle har node ke liye inDegree nikal lo by iterating over the adjacency list.
Phir ek queue banao, jisme initially vo sare nodes daalo jinka inDegree == 0 ho.
Queue se top element uthao, ans me daalo, fir uske sare adjacent nodes traverse karo aur
unka inDegree-- karo. Agar kisi ka inDegree 0 ho jaye to usko queue me daal do. Jab tak queue empty na ho,
ye process chalte raho.



class Solution{
    public:
        vector<int> topoSort(int V, vector<int> adj[]){
           vector<int>ans;
           vector<int>inDegree(V,0);
           for(int i=0;i<V;i++)
           {
            for(auto it:adj[i])
            {
                inDegree[it]++;
            }
           }
            queue<int>q;
            for(int i=0;i<V;i++)
            {
                if(inDegree[i]==0)
                q.push(i);
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
                    q.push(it);
                }
    
            }
            return ans;
           
        }
    };

class DisjointSet{
vector<int>parent;
vector<int>rank;
public:
DisjointSet(int n){
    parent.resize(n+1);
    rank.resize(n+1,0);

    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    
}

int findUPar(int node)
{
    if(node==parent[node])
    return node;

    return parent[node]=findUPar(parent[node]);
}

void unionByRank(int u,int v)
{
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);

    if(ulp_u==ulp_v)
    return;

    if(rank[ulp_u]>rank[ulp_v])
    {
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_v]>rank[ulp_u])
    {
        parent[ulp_u]=ulp_v;
    }
    else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
    }
}
};




class Solution{
public:


    int solve(int n, vector<vector<int>> &Edge){

         int size = Edge.size();
        
        /* Return -1 if connecting all 
        vertices is not possible */
        if(size < n-1) return -1;


           DisjointSet ds(n);
        int count=n;
        for(auto &it:Edge)
        {
            
               if(ds.findUPar(it[0])!=ds.findUPar(it[1]))
        {
            count--;
            ds.unionByRank(it[0],it[1]);
        }
        }
     
     //sbkounion krne ke baad jitne components ban skte hain bana do, 
     //fir total components agar n bane hain to hume total n-1 edges chahiye honge na unko combine krne ke liye
     
        return count-1;
    }
};


// Time Complexity:O(m*4*alpha) where m is the number of edges and alpha is the inverse Ackermann function which is nearly constant
// Space Complexity:O(n) due to the parent and rank vectors in the DisjointSet class, where n is the number of vertices.
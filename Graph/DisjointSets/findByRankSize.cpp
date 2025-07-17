class DisjointSet {
public:
  vector<int>rank;
      vector<int>parent;
      vector<int>size;

    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
size.resize(n+1,1);

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

    bool find(int u, int v) {
        return findUPar(u)==findUPar(v);
    }

    void unionByRank(int u, int v) {
       int ulp_u=findUPar(u);
       int ulp_v=findUPar(v);

       if(ulp_u==ulp_v)
       return;

       if(rank[ulp_u]>rank[ulp_v])
       {
            parent[ulp_v]=ulp_u;
       }
       else if(rank[ulp_u]<rank[ulp_v])
       {
            parent[ulp_u]=ulp_v;
       }
       else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
       }
    }

    void unionBySize(int u, int v) {
       int ulp_u=findUPar(u);
       int ulp_v=findUPar(v);
       if(ulp_u==ulp_v)
       return;

       if(size[ulp_u]<size[ulp_v])
       {
        //parent banega v
        parent[ulp_u]=ulp_v;
       }

       else if(size[ulp_v]<size[ulp_u])
       {
        parent[ulp_v]=ulp_u;
       }
       else{
           parent[ulp_v]=ulp_u;
           size[ulp_u]+=size[ulp_v];
       }

    }
};

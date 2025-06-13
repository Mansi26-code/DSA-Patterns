class Solution{
public:

vector<int>parent;
vector<int>rank;

int find(int x)
{
    if(x==parent[x])
    return x;


    return parent[x]=find(parent[x]);
}

void unionSet (int x,int y)
{
    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent==y_parent)
    {
        return;
    }

    if(rank[x_parent]>rank[y_parent])
    {
        parent[y_parent]=x_parent;
    }

    else if(rank[y_parent]>rank[x_parent])
    {
        parent[x_parent]=y_parent;
    }
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }

}
    int solve(int n, vector<vector<int>> &Edge){
        if(Edge.size()<n-1)
        return -1;

        parent.resize(n);
        rank.resize(n,0);
       
       for(int i=0;i<n;i++)
       {
        parent[i]=i;
       }

       int components=n;

       for(auto &vec:Edge)
       {
        if(find(vec[0])!=find(vec[1]))
        {
            components--;
            unionSet(vec[0],vec[1]);
        }
       }
       return components-1;

    }
};


Time Complexity:O(m * alpha(n)) where m is the number of edges and alpha(n) is the inverse Ackermann function, practically O(m) due to path compression and union by rank. The initialization loop contributes O(n), but is dominated by the edges loop.
Space Complexity:O(n) due to the parent and rank vectors, which store information for each of the 'n' nodes.
class Solution {
public:
typedef pair<int,pair<int,int>>P;
vector<vector<int>>directions={{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,-1}, {-1,1}  ,{1,-1}   };
bool isSafe(int x,int y, int m,int n)
{
    return x>=0 && x<m && y>=0 && y<n;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0 || grid[0][0]!=0)
        return -1;

        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        priority_queue<P, vector<P>, greater<P>>pq; //{{wt,{x,y}}}
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto top=pq.top();
            int d=top.first;
            int x=top.second.first;
            int y=top.second.second;
            pq.pop();
            for(auto &dir:directions)
            {
                int nx=x+dir[0];
                int ny=y+dir[1];
                 int distance=1;
                if(isSafe(nx,ny,m,n) && grid[nx][ny]==0 && d+distance<dist[nx][ny])
                {
                    pq.push({d+distance,{nx,ny}});
                        dist[nx][ny]=d+distance;
                        
                    
                }

            }
        }
         if(dist[m-1][n-1]==1e9)
         return -1;


         return dist[m-1][n-1]+1;
    }
};

Time Complexity:The time complexity is O(m*n*log(m*n)) 
Space Complexity:The space complexity is O(m*n)
class Solution {
public:
vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1)
                {
                    if(grid[i][j]==1)
                    {
                        vis[i][j]=1;
                    q.push({i,j});
                    }
                }
            }
        }

        while(!q.empty())
        {
           auto top=q.front();
           q.pop();
           int x=top.first;
           int y=top.second;

           for(auto &dir:directions)
        {
            int new_x=x+dir[0];
            int new_y=y+dir[1];

            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && grid[new_x][new_y]==1  && vis[new_x][new_y]==0)
            {
                q.push({new_x,new_y});
                vis[new_x][new_y]=1;
            }
        }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                count++;
            }
        }
        return count;
        
    }
};

✅ Time Complexity (TC):
O(m × n)

✅ space Complexity (SC):
O(m × n)
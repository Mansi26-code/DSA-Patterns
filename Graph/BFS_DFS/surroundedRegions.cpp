class Solution {
public:
bool isSafe(int new_x, int new_y, int m,int n)
{
    return new_x>=0 && new_x<m && new_y>=0 && new_y<n;
}
vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        //checking for first row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
            {
                vis[0][j]=1;
                q.push({0,j});
            }
        }

        //checking last row
                for(int j=0;j<n;j++)
        {
            if(board[m-1][j]=='O')
            {
                vis[m-1][j]=1;
                q.push({m-1,j});
            }
        }

        //checking first col
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                vis[i][0]=1;
                q.push({i,0});
            }
        }

             for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O')
            {
                vis[i][n-1]=1;
                q.push({i,n-1});
            }
        }


        while(!q.empty())
        {
            auto top=q.front();
            int x=top.first;
            int y=top.second;
            q.pop();
            for(auto &dir:directions)
            {
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                if(isSafe(new_x,new_y,m,n) && vis[new_x][new_y]==0 && board[new_x][new_y]=='O')
                {
                    vis[new_x][new_y]=1;
                    q.push({new_x,new_y});
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && board[i][j]=='O')
                {
                    board[i][j]='X';
                   
                }
            }
        }
    }
};



T.C=O(m*n)
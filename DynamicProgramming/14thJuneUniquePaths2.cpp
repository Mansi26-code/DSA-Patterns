class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
        return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0]==1)
            {
              break;
            }
              dp[i][0]=1;
        }

          for(int j=0;j<n;j++)
        {
            if(obstacleGrid[0][j]==1)
            {
               break;
            }
              dp[0][j]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]!=1)
                {
                    dp[i][j]= dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1]==1?0:dp[m-1][n-1];
    }
};
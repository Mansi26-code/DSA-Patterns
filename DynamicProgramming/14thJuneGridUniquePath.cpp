class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dp[i][0] = 1;//only 1 way to reach down

        for (int j = 0; j < n; j++) dp[0][j] = 1;// only 1 way to reach right

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};


//TC & SC= O(m*n)


//memoization

class Solution {
public:
int solve(int i,int j, int m, int n, vector<vector<int>>&dp)
{
  

    if(dp[i][j]!=0)
    return dp[i][j];
    dp[0][0]=1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             if(i==0 && j==0) continue;
            //int down
            int left=0,up=0;
            if(i>0)
            {
                up=dp[i-1][j];
            }
            //going right
            if(j>0)
            {
                 left=dp[i][j-1];
            }

            dp[i][j]=left+up;
        }
    }
    return dp[m-1][n-1];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return solve(0,0,m,n,dp);
    }
};
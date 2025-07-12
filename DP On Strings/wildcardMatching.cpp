class Solution {
public:
    bool wildCard(string str, string pat) {
        
        int m=str.size();
        int n=pat.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;

        for(int j=1;j<=n;j++)
        {
            if(pat[j-1]=='*')
            {
                dp[0][j]=dp[0][j-1];
            }

            else {
                dp[0][j]=false;
            }
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str[i-1]==pat[j-1] || pat[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pat[j-1]=='*')
                {
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];

    }
};


//TC & SC= O(m*n)
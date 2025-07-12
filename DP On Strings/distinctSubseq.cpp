class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        int mod=1e9+7;
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    //agar match kiya to do options honge
                    //1. t ko bhi aage badhao and s ko bhi
                    //2. s ke character ko skip kro, pr t ke char ko nhi kr skte
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else
                {  //s ke character ko skip kro, pr t ke char ko nhi kr skte
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
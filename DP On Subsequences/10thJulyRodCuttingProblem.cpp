class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
      //itna to smjh aa rha h ki index ka khel h, aur cost bata rha 
      //us index ka value
      int l=price.size();
      vector<vector<int>>dp(l+1, vector<int>(n+1,0));

      for(int i=1;i<=l;i++)
      {
        for(int j=0;j<=n;j++)
        {
           if(i<=j)
           {
            dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
           }
           else
           {
            dp[i][j]=dp[i-1][j];
           }
        }
      }
      return dp[l][n];
    }
};


//SC &TC=O(n*l)
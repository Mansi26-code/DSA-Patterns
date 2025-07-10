class Solution{
	public:
	int perfectSum(vector<int>&arr, int K){
                  int n=arr.size();
int target=K;
int mod=1e9+7;
      vector<vector<int>>dp(n+1,vector<int>(target+1,0));
      

      //dp[i][0]=true;
      for(int i=0;i<=n;i++)
      {
        dp[i][0]=1;
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=target;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
      }
      return dp[n][target];

    
	}
};

//tc & sc=O(n*target)
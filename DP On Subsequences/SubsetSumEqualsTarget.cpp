class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n=arr.size();

      vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
      

      //dp[i][0]=true;
      for(int i=0;i<=n;i++)
      {
        dp[i][0]=true;
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=target;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
      }
      return dp[n][target];

    }
};


Time Complexity:O(n*target) due to the nested loops iterating up to n and target, respectively, plus O(n) for initializing the first column of the dp table.
Space Complexity:O(n*target) to store the dp table of size (n+1)*(target+1).
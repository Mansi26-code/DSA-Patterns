class Solution{

  public:
	int minDifference(vector<int>&arr, int n)  { 
       
       int totSum=accumulate(arr.begin(), arr.end(),0);
       vector<vector<bool>>dp(n+1,vector<bool>(totSum/2+1,false));

       for(int i=0;i<=n;i++)
       {
        dp[i][0]=true;
       }

       for(int i=1;i<=n;i++)
       {
        for(int j=0;j<=totSum/2;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];

            else 
            dp[i][j]=dp[i-1][j];
        }
       }


     int minDiff=INT_MAX;
  for(int i = 0; i <= totSum/2; i++)

     {
if(dp[n][i])        {
minDiff = min(minDiff, abs(totSum - 2*i));
        }
     }
     return minDiff;
	} 
};

class Solution {
  public:
  vector<int>LIS(vector<int>arr)
  {
    int n=arr.size();
    vector<int>dp(n,1);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(arr[i]>arr[j])
        {
          dp[i]=max(dp[i],1+dp[j]);
        }
      }
    }
    return dp;
  }


    vector<int>LDS(vector<int>arr)
  {
    int n=arr.size();
    vector<int>dp(n,1);
    for(int i=n-1;i>=0;i--)
    {
      for(int j=n-1;j>=i;j--)
      {
        if(arr[i]> arr[j])
        {
          dp[i]=max(dp[i],1+dp[j]);
        }
      }
    }
    return dp;
  }
    int LongestBitonicSequence(vector<int> arr) {
         int longest=1;
         int n=arr.size();
         vector<int>lis(LIS(arr));
         vector<int>lds(LDS(arr));
         for(int i=0;i<n;i++)
         {
          longest=max(longest,lis[i]+lds[i]-1);
         }
         return longest;
    }
};

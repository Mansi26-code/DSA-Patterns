class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=accumulate(nums.begin(),nums.end(),0);
         if (target % 2 != 0)
            return false;
        int n=nums.size();
        int sum=target/2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));

        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                  dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
      return dp[n][sum];

    }
};

S1+S2=TotalSum
S1==S2, 
so S1= TotalSUM/2


//TC= O(n*sum)
//SC=O(n*sum)
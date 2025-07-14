class Solution {
public:
    int numberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                  if(dp[i]==dp[j]+1)
                  {
                    count[i]+=count[j];
                  }
                  else if(dp[i]<dp[j]+1)
                  {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                  }

                }
            }
        }
        int ans=0;
        int LIS=*max_element(dp.begin(),dp.end());

        for(int i=0;i<n;i++)
        { 
            if(dp[i]==LIS)
            ans+=count[i];
        }
        return ans;
    }
};
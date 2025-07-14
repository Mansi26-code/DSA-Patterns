class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return {};
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int maxLen=1;
        int maxIndex=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxLen)
            {
                maxLen=dp[i];
                maxIndex=i;
            }
        }

        vector<int>res;
        int k=maxIndex;
        while(k!=-1)
        {
            res.push_back(nums[k]);
           k= parent[k];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
public:
int func(vector<int>&arr, int s,int e)
{
    return *max_element(arr.begin()+s, arr.begin()+e+1);
}
int solve(vector<int>&arr,int i, int k, vector<int>&dp)
{
    int n=arr.size();
    if(i==n)
    {
        return 0;
    }

    if(dp[i]!=-1)
    return dp[i];

    int maxi=0;
    int ans=0;

    for(int l=1;l<=k && i+l-1<n;l++)
    {
        int partMax=func(arr,i,i+l-1);
        int total=partMax*l+solve(arr,i+l,k,dp);
        ans=max(ans,total);
    }
    return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,0,k,dp);
    }
};
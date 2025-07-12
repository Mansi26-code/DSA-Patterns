//memoisation
class Solution{
	public:

    int solve(vector<int>&arr, int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)
        return 0;
 
     if(dp[i][j]!=-1)
     return dp[i][j];

        int mini=INT_MAX;

        for(int k=i;k<j;k++)
        {
            int ans=solve(arr,i,k,dp)+ solve(arr,k+1,j,dp)+ arr[i-1]*arr[k]*arr[j];
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
		int matrixMultiplication(vector<int>& nums){
            //your code goes here
            int N=nums.size();
                  vector<vector<int>> dp(N,vector<int>(N,-1));
            int i=1;
            int j=N-1;
            return solve(nums,i,j,dp);
    	}
};



//recursive

class Solution{
	public:

    int solve(vector<int>&arr, int i,int j)
    {
        if(i==j)
        return 0;

        int mini=INT_MAX;

        for(int k=i;k<j;k++)
        {
            int ans=solve(arr,i,k)+ solve(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
            mini=min(mini,ans);
        }
        return mini;
    }
		int matrixMultiplication(vector<int>& nums){
            //your code goes here
            int N=nums.size();
            int i=1;
            int j=N-1;
            return solve(nums,i,j);
    	}
};

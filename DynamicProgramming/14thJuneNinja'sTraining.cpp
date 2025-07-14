class Solution {
public:

int solve(int day, int last, vector<vector<int>>&matrix, vector<vector<int>>&dp)
{
    if(dp[day][last]!=-1)
    return dp[day][last];

    if(day==0)
    {
        int maxi=0;
        for(int i=0;i<=2;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,matrix[0][i]);

            }
         
        }
        return dp[day][last]=maxi;
        
    }
    int maxi=0;
    for(int i=0;i<=2;i++)
    {
       if(i!=last)
       {
         int activity=matrix[day][i]+ solve(day-1,i,matrix,dp);
         maxi=max(maxi,activity);
       }
    }
    return dp[day][last]=maxi;
  
}
    int ninjaTraining(vector<vector<int>>& matrix) {
        int day=matrix.size();
        vector<vector<int>>dp(day,vector<int>(4,-1));
        int last=3;
        return solve(day-1,last,matrix,dp);
    }
};
// Given two strings, initial and target. The task is to modify initial by performing a series of operations to make it equal to target.



// In one operation:



// Add one character only at the beginning or the end of initial.
// Remove one character only from the beginning or the end of initial.


// Return the minimum number of operations required to transform initial into target.






class Solution {
public:
    int minOperations(string initial, string target) {
      int n=initial.size();
      int m=target.size();

      int LCS=0;
      vector<vector<int>>dp(n,vector<int>(m,0));
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(initial[i]==target[j])
            {

         
            if(i>=1 && j>=1)
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=1;//agar stating of string ho
            }
            LCS=max(LCS, dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
      }
      return n*m-2*LCS;
    }
};
class Solution {
public:
#define ll long long
const int MOD=1e9+7;


int solve(int i,int j, int isTrue,string &s, vector<vector<vector<ll>>> &dp)
   {
      if(i>j)
      return 0;

      if(i==j)
      {
        if(isTrue==1)
        return s[i]=='T'?1:0;
        else return s[i]=='F'?1:0;
      }
      if(dp[i][j][isTrue]!=-1)
      return dp[i][j][isTrue];

      ll ways=0;
      for(int ind=i+1;ind<j;ind+=2)
      {
         ll LT=solve(i,ind-1,1,s,dp);
         ll LF=solve(i,ind-1,0,s,dp);
         ll RT=solve(ind+1,j,1,s,dp);
         ll RF= solve(ind+1,j,0,s,dp);

         if(s[ind]=='&')
         {
            if(isTrue)
            ways=(ways+(LT*RT)%MOD)%MOD;
            else ways=(ways+ (LT*RF)%MOD+ (LF*RT)%MOD +(LF*RF)%MOD)%MOD;
         }

         else if(s[ind]=='|')
         {
            if(isTrue)
            {
                ways=(ways+(LF*RT)%MOD + (LT*RF)%MOD+ (LT*RT)%MOD )%MOD;
            }
            else{
                ways=(ways+(LF*RF)%MOD)%MOD;
            }
         }

         else{
            if(isTrue)
            ways=(ways+(LF*RT)%MOD + (RF*LT)%MOD)%MOD;
            else{
                ways=(ways+(LT*RT)%MOD + (LF*RF)%MOD)%MOD;
            }
         }
      }
      return dp[i][j][isTrue]=ways;
   }
   
    int countTrue(string s) {
        // Your code goes here
        int n=s.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
        return solve(0,n-1,1,s,dp);
    }
};

   
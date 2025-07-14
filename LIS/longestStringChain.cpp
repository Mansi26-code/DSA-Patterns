class Solution {
public:
bool isValid(string &longer, string &shorter)
{
  if(longer.size()!=shorter.size()+1)
  return false;

  int i=0,j=0;
  while(i<longer.size())
  {
    if(j<shorter.size() && longer[i]==shorter[j])
    {
        i++;
        j++;
    }
    else
    {
        i++;
    }
  }
  return j==shorter.size();
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](const string &a, string &b){
            return a.size()<b.size();
        });

        vector<int>dp(n,1);
        int maxi=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].size()-words[j].size()==1&& isValid(words[i],words[j]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        sort(bt.begin(),bt.end());
        long long cnt=0;
        long long ans=0;
        long long n=bt.size();
        for(int i=0;i<n-1;i++)
        {
          cnt+=bt[i];
          ans+=cnt;
        }
        return ans/n;
    }
};

//Time Complexity:O(n log n)
//SC=O(1)
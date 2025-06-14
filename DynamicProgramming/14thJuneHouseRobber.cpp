class Solution {
public:

 int nonAdjacent(vector<int>& nums) {
           int n = nums.size();
        if (n == 0) return 0;           // Edge case
        if (n == 1) return nums[0];     // Only one element

           vector<int>dp(n,0);
           dp[0]=nums[0];
          dp[1] = max(nums[0], nums[1]);
           for(int i=2;i<n;i++)
           {
            dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
           }
           return dp[n-1];

    }
    int houseRobber(vector<int>& money) {
  int n = money.size();
        if (n == 0) return 0;
        if (n == 1) return money[0];

           vector<int>arr1(money.begin()+1,money.end());
           vector<int>arr2(money.begin(),money.end()-1);

           return max(nonAdjacent(arr1),nonAdjacent(arr2));
    }
};

//sc and tc =O(n)
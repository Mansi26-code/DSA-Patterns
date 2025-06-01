class Solution {
public:    	
    void solve(vector<int>& nums, int i, int sum, int k, int& count)
    {
        if(i == nums.size()) {
            if(sum == k) count++;  // check at the leaf level
            return;
        }

        // include current element
        solve(nums, i + 1, sum + nums[i], k, count);

        // exclude current element
        solve(nums, i + 1, sum, k, count);
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        int count = 0;
        solve(nums, 0, 0, k, count);
        return count;
    }
};

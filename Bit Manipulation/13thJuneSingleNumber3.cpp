//Brute force approach : using map
//TC & SC= O(n)

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        // your code goes here
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto& it : mp) {
            if (it.second == 1) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

  

//optimized approach

//TC= O(n)
//SC=O(1)
  class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        // your code goes here
        int n = nums.size();
        long XOR = 0;
        for (int i = 0; i < n; i++) {
            XOR = XOR ^ nums[i];
        }

        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        int XOR1 = 0, XOR2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            }

            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }

        if (XOR1 < XOR2) return {XOR1, XOR2};

        return {XOR2, XOR1};
    }
};
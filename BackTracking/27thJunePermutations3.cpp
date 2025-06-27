// Leetcode 3437. Permutations III
// Return all permutations of 1..n where no two adjacent elements are both odd or both even. Return them in lexicographical order.


class Solution {
public:
    // Helper function to generate permutations recursively
    void solve(int index, vector<int>& nums, vector<vector<int>>& res) {
        // Base case: If the permutation is complete
        if (index == nums.size()) {
            bool isValid = true;
            // Check that no two adjacent elements have the same parity
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] % 2 == nums[i - 1] % 2) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                res.push_back(nums);
            }
            return;
        }

        // Try swapping each element at index and recurse
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(index + 1, nums, res);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(int n) {
        vector<vector<int>> res;
        vector<int> nums;

        // Fill nums with 1 to n
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // Generate all permutations
        solve(0, nums, res);

        // Sort lexicographically
        sort(res.begin(), res.end());

        return res;
    }
};


// Generating all permutations: TC=  O(n!*n)

//sc= O(k × n + n)

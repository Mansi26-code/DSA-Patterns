/*
    🔢 Problem: Find Distinct Expressions (Easy)
    -----------------------------------------------------
    Given an integer array nums, you need to return all 
    **distinct results** formed by inserting mathematical 
    '+' (addition) or '-' (subtraction) between each element 
    of nums and evaluating the resulting expression.

    👉 Return the results in **increasing order**.

    🔁 Constraints:
    - 1 <= nums.length <= 10
    - 1 <= nums[i] <= 1000

    🧠 Approach:
    -----------------------------------------------------
    We will use **Depth-First Search (DFS)** to explore all 
    combinations of '+' and '-' between elements. Starting 
    from index 1 (since the first number has no operator 
    before it), we recursively:
    - Add nums[i] to the current sum.
    - Subtract nums[i] from the current sum.

    At the end of the recursion (base case), we insert the 
    final sum into a set to ensure distinct values. Finally, 
    we convert the set to a sorted vector for output.

    ✅ Time Complexity: O(2^(n-1)) where n = nums.size()
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔁 Recursive DFS function to explore all expressions
    void dfs(vector<int>& nums, int idx, int currSum, set<int>& result) {
        // ⛔ Base case: If we have used all elements, insert result
        if (idx == nums.size()) {
            result.insert(currSum);
            return;
        }

        // ➕ Try adding the current number
        dfs(nums, idx + 1, currSum + nums[idx], result);

        // ➖ Try subtracting the current number
        dfs(nums, idx + 1, currSum - nums[idx], result);
    }

    // 🔓 Main function to be called
    vector<int> distinctExpressions(vector<int>& nums) {
        set<int> result; // To store distinct results in sorted order
        dfs(nums, 1, nums[0], result); // Start DFS from index 1 with first number as initial sum
        return vector<int>(result.begin(), result.end()); // Convert set to vector for output
    }
};

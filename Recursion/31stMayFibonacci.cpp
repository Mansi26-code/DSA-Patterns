/*
🔸 Problem: Compute the n-th Fibonacci number.
🔹 Definition: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2) for n>1.
*/

class Solution {
public:
    // ✅ Brute Force Recursive Approach
    // Time Complexity: O(2^n) => exponential due to overlapping subproblems
    // Space Complexity: O(n) recursion stack

    int fibRecursive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    // ✅ Optimized: Top-Down Memoization (Dynamic Programming)
    // Time Complexity: O(n)
    // Space Complexity: O(n) for dp array + O(n) recursion stack

    int fibMemo(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
        return dp[n];
    }

    // ✅ Main function to call
    int fib(int n) {
        // Use memoization for better performance
        vector<int> dp(n + 1, -1);
        return fibMemo(n, dp);
    }
};

class Solution {
   private:
    /* Helper function to find the prime
    factorization of a number */
    vector<int> primeFact(int n) {
        // To store the result
        vector<int> ans;

        /* Keep dividing the number with
        2 till it is possible */
        while (n % 2 == 0) {
            // Add 2 to result
            ans.push_back(2);

            // Update the number
            n = n / 2;
        }

        /* Start iterating from 3 skipping
        one number (because n is now odd) */
        for (int i = 3; i <= sqrt(n); i += 2) {
            // While i divides n
            while (n % i == 0) {
                // Store the number
                ans.push_back(i);

                // Update the number
                n = n / i;
            }
        }

        // Edge case
        if (n > 2) ans.push_back(n);

        // Return the result
        return ans;
    }

   public:
    /* Function to get the prime
    factorization of all the number */
    vector<vector<int>> primeFactors(vector<int>& queries) {
        // To store the answer
        vector<vector<int>> ans;

        // Iterate on each number in query
        for (int i = 0; i < queries.size(); i++) {
            /* Function call to get the prime
            factorization of current number */
            ans.push_back(primeFact(queries[i]));
        }

        // Return the answer
        return ans;
    }
};


Time Complexity:The time complexity is O(q * sqrt(m)), where q is the number of queries and m is the maximum value in the queries array.
Space Complexity:The space complexity is O(k), where k is the total number of prime factors across all factorizations.
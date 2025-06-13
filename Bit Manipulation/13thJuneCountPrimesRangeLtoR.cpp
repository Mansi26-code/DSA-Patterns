class Solution {
public:
    vector<int> primesInRange(vector<vector<int>>& queries) {
        // Vector to store the results of each query
        vector<int> result; 

        for (auto& query : queries) {
            int l = query[0]; // Starting point of the range
            int r = query[1]; // Ending point of the range
            int count = 0; // Counter for the number of prime numbers

            for (int j = l; j <= r; j++) {
                // Check if the number is prime  
                if (isPrime(j)) 
                    count++;
            }
            // Store the result for the current query
            result.push_back(count); 
        }

        return result;
    }

private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};

Time Complexity:O(q * (r - l) * sqrt(r)), where q is the number of queries, l is the start of the range, and r is the end of the range.
Space Complexity:O(q), where q is the number of queries, due to storing the count of primes for each query.
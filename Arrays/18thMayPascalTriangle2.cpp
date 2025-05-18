/*
Problem: Pascal's Triangle II
-------------------------------
Return the r-th row (1-indexed) of Pascal’s Triangle.

Approach:
Use the formula C(n, k) to fill values in the row:
    row[i] = C(r - 1, i)
We use an efficient method to compute nCr iteratively.
*/

class Solution {
    public:
        // Function to compute a single value of nCr
        int nCr(int n, int r) {
            if (r > n - r) r = n - r;  // Symmetry optimization
    
            int res = 1;
    
            for (int i = 0; i < r; i++) {
                res *= (n - i);       // Numerator: n * (n - 1) * ...
                res /= (i + 1);       // Denominator: 1 * 2 * ...
            }
    
            return res;
        }
    
        // Function to return the r-th row of Pascal's Triangle (1-indexed)
        vector<int> pascalTriangleII(int r) {
            vector<int> row;
    
            // The r-th row (1-indexed) is built from C(r-1, 0) to C(r-1, r-1)
            for (int i = 0; i < r; i++) {
                row.push_back(nCr(r - 1, i));
            }
    
            return row;
        }
    };
    
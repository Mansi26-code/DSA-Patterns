/*
Problem: Pascal's Triangle (I)
---------------------------------
Return the value at the r-th row and c-th column of Pascal's Triangle.
(1-based indexing)

Concept:
Value at position (r, c) in Pascal’s Triangle is: C(r-1, c-1)
Where C(n, r) = n! / (r! * (n - r)!)

To avoid factorial overflow, we use iterative formula:
C(n, r) = (n * (n - 1) * ... * (n - r + 1)) / (1 * 2 * ... * r)
*/

class Solution {
    public:
        // Function to return value at (r, c) in Pascal's Triangle
        int pascalTriangleI(int r, int c) {
            return nCr(r - 1, c - 1);  // Convert 1-based index to 0-based for calculation
        }
    
        // Efficient computation of nCr without using factorials
        int nCr(int n, int r) {
            // nCr is same as nC(n - r), we take the smaller one to reduce computation
            if (r > n - r)
                r = n - r;
    
            // Base case: nC1 = n
            if (r == 1)
                return n;
    
            int res = 1;
    
            /*
            Instead of computing full factorials, we calculate:
            nCr = (n * (n - 1) * ... * (n - r + 1)) / (1 * 2 * ... * r)
    
            For example, 5C3 = (5 * 4 * 3) / (1 * 2 * 3)
            */
            for (int i = 0; i < r; i++) {
                res *= (n - i);      // Numerator grows from n down to (n - r + 1)
                res /= (i + 1);      // Denominator grows from 1 up to r
            }
    
            return res;
        }
    };
    
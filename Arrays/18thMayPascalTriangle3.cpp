/*
Problem: Pascal's Triangle (III)
----------------------------------
Generate Pascal's Triangle with `n` rows.

Approach:
For each row `i` (0-indexed), we generate elements from j = 0 to i using:
    triangle[i][j] = C(i, j) = i! / (j! * (i - j)!)
To compute C(i, j) efficiently, we use an iterative formula to avoid factorial overflow.
*/

class Solution {
    public:
        // Efficient computation of nCr using iteration instead of factorials
        int nCr(int n, int r) {
            // nCr = nC(n - r) to reduce number of multiplications
            if (r > n - r)
                r = n - r;
    
            long long res = 1;
    
            /*
            We calculate:
            C(n, r) = (n * (n - 1) * ... * (n - r + 1)) / (1 * 2 * ... * r)
            Avoids large factorials and keeps result within bounds.
            */
            for (int i = 0; i < r; i++) {
                res *= (n - i);       // Numerator builds down from n
                res /= (i + 1);       // Denominator builds up from 1
            }
    
            return (int)res;
        }
    
        // Generates the entire Pascal's Triangle up to row n-1
        vector<vector<int>> pascalTriangleIII(int n) {
            vector<vector<int>> triangle(n);  // triangle[i] stores the i-th row
    
            for (int i = 0; i < n; i++) {
                triangle[i].resize(i + 1);  // i-th row has (i + 1) elements
    
                for (int j = 0; j <= i; j++) {
                    triangle[i][j] = nCr(i, j);  // Fill each element with C(i, j)
                }
            }
    
            return triangle;
        }
    };
    
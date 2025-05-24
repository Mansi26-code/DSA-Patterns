// LeetCode 74: Search a 2D Matrix
// ✅ Author: [Your Name]
// ✅ Description: Brute force and optimized solution using matrix properties

class Solution {
    public:
    
        /*
        ✅ Brute Force Approach:
    
        - Loop through every element in the matrix and compare with the target.
        - Straightforward but inefficient for large matrices.
    
        🔄 Time Complexity: O(m * n)
        🧠 Space Complexity: O(1)
        */
    
        bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();         // number of rows
            int n = matrix[0].size();      // number of columns
    
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == target)
                        return true;
                }
            }
    
            return false;
        }
    
        /*
        ✅ Optimized Approach (Staircase Search):
    
        - Start from the **top-right** corner.
        - If current element == target → found.
        - If current element > target → move left (decrease column).
        - If current element < target → move down (increase row).
        - Leverages the sorted row and column structure of matrix.
    
        🔄 Time Complexity: O(m + n)
        🧠 Space Complexity: O(1)
        */
    
        bool searchMatrix(vector<vector<int>> &matrix, int target) {
            int m = matrix.size();         // number of rows
            int n = matrix[0].size();      // number of columns
    
            int row = 0, col = n - 1;      // start from top-right corner
    
            while (row < m && col >= 0) {
                if (matrix[row][col] == target) {
                    return true;           // target found
                }
                else if (matrix[row][col] > target) {
                    col--;                 // move left
                }
                else {
                    row++;                 // move down
                }
            }
    
            return false;                  // target not found
        }
    };
    
// Given a 2D matrix, return all elements of the matrix in spiral order, i.e., move in a clockwise spiral from the top-left element.


class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;                  // To store elements in spiral order
            int m = matrix.size();            // Total rows
            int n = matrix[0].size();         // Total columns
    
            // Define the four boundaries of the matrix
            int startRow = 0, endRow = m - 1;
            int startCol = 0, endCol = n - 1;
    
            // Traverse the matrix in spiral form until boundaries overlap
            while (startRow <= endRow && startCol <= endCol) {
    
                // 🔹 Step 1: Traverse the top row from left to right
                for (int i = startCol; i <= endCol; i++) {
                    ans.push_back(matrix[startRow][i]);
                }
                startRow++;  // Move top boundary down
    
                // 🔹 Step 2: Traverse the rightmost column from top to bottom
                for (int i = startRow; i <= endRow; i++) {
                    ans.push_back(matrix[i][endCol]);
                }
                endCol--;    // Move right boundary left
    
                // 🔹 Step 3: Traverse the bottom row from right to left (if any rows left)
                if (startRow <= endRow) {
                    for (int i = endCol; i >= startCol; i--) {
                        ans.push_back(matrix[endRow][i]);
                    }
                    endRow--;  // Move bottom boundary up
                }
    
                // 🔹 Step 4: Traverse the leftmost column from bottom to top (if any columns left)
                if (startCol <= endCol) {
                    for (int i = endRow; i >= startRow; i--) {
                        ans.push_back(matrix[i][startCol]);
                    }
                    startCol++;  // Move left boundary right
                }
            }
    
            return ans;  // Return the collected spiral order
        }
    };

    
    //TC=O(m*n)
    //SC=O(1)
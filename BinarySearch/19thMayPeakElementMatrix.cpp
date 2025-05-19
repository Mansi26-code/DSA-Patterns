/*
🧾 Problem: Find a Peak Element in a 2D Matrix

A peak element in a 2D matrix is an element that is strictly greater than its neighbors (left and right).
Given a matrix `mat`, return the position (row, col) of **any** peak element.

Conditions:
- The matrix has dimensions `n x m`.
- You can assume that the peak always exists.
- Only vertical and horizontal neighbors are considered.
- Optimize using binary search on columns.

Approach:
Use Binary Search on columns:
- For the middle column, find the global maximum in that column.
- Compare it with its left and right neighbors.
- Based on which side is greater, eliminate half the search space.
*/

class Solution {
    public:
        // Helper function to find the index of the maximum element in a specific column
        int maxElement(vector<vector<int>>& arr, int col) {
            int n = arr.size();            // Total number of rows
            int max_val = INT_MIN;         // Initialize max value to negative infinity
            int index = -1;                // To store the row index of max element
    
            // Traverse each row in the given column to find the max element
            for (int i = 0; i < n; i++) {
                if (arr[i][col] > max_val) {
                    max_val = arr[i][col];
                    index = i;
                }
            }
    
            return index; // Return the row index where the maximum is found
        }
    
        // Main function to find a peak element in the 2D grid
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n = mat.size();          // Total rows
            int m = mat[0].size();       // Total columns
    
            int low = 0;                 // Start of binary search on columns
            int high = m - 1;            // End of binary search
    
            while (low <= high) {
                int mid = (low + high) / 2;   // Middle column
                int row = maxElement(mat, mid); // Find max element's row in mid column
    
                // Get the values of left and right neighbors (handle boundary cases)
                int left = mid - 1 >= 0 ? mat[row][mid - 1] : INT_MIN;
                int right = mid + 1 < m ? mat[row][mid + 1] : INT_MIN;
    
                // Check if the mid element is a peak
                if (mat[row][mid] > left && mat[row][mid] > right) {
                    return {row, mid}; // Found the peak
                }
                // If the left neighbor is greater, search left half
                else if (left > mat[row][mid]) {
                    high = mid - 1;
                }
                // Else, search right half
                else {
                    low = mid + 1;
                }
            }
    
            // No peak found (should never hit this due to problem constraints)
            return {-1, -1};
        }
    };
    
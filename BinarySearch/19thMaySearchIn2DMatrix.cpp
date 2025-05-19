/*
Search in a 2D Matrix:
Given an m x n matrix where each row is sorted and the first element of each row is greater than the last of the previous,
determine if a target value exists using binary search.
*/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>> &mat, int target) {
            int m = mat.size();       // Number of rows
            int n = mat[0].size();    // Number of columns
            int start = 0;
            int end = m * n - 1;      // Treat matrix as a 1D array of size m*n
    
            while (start <= end) {
                int mid = start + (end - start) / 2;
    
                // Convert 1D mid index to 2D row and column
                int midElement = mat[mid / n][mid % n];
    
                if (midElement == target) {
                    return true;      // Target found
                } else if (midElement < target) {
                    start = mid + 1;  // Discard left half
                } else {
                    end = mid - 1;    // Discard right half
                }
            }
    
            return false;  // Target not found
        }
    };
    
    /*
    Time Complexity: O(log(m * n)) – Binary search over the entire matrix treated as a 1D array.
    Space Complexity: O(1) – No extra space used.
    */
19thMay    
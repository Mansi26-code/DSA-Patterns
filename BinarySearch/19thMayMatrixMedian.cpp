/*
🧾 Problem: Find the Median in a Row-Wise Sorted Matrix

You are given a matrix of size n x m, where each row is sorted in non-decreasing order.
Your task is to find the **median** of the matrix.

👉 Note:
- The matrix is not fully sorted, but each row is individually sorted.
- The median is the element at position (n * m) / 2 in the **sorted order** of all elements.

Approach:
1. Use **Binary Search** on the value range [min element, max element] in the matrix.
2. For each mid-value, count how many elements are **less than or equal to mid** using upper bound.
3. If this count is less than or equal to required position (n*m/2), shift the binary search to the right.
4. Otherwise, shift to the left.
5. The first number where this condition fails is the median.
*/

class Solution {
    public:
    
        // 📌 Function to get the index of the first element > x in a sorted array (upper bound)
        int upperBound(vector<int> nums, int x, int m) {
            int s = 0, e = m - 1;
            int ans = m; // Default if all elements <= x
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] > x) {
                    ans = mid;      // Candidate index
                    e = mid - 1;    // Look in left half
                } else {
                    s = mid + 1;    // Look in right half
                }
            }
    
            return ans;
        }
    
        // 📌 Count how many numbers are <= x in the whole matrix using row-wise upper bounds
        int countSmallEqual(vector<vector<int>> matrix, int n, int m, int x) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += upperBound(matrix[i], x, m); // Count elements ≤ x in each row
            }
            return cnt;
        }
    
        // 🔍 Main function to find median
        int findMedian(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            // Step 1: Define search space for values (min and max of matrix)
            int low = INT_MAX;
            int high = INT_MIN;
    
            for (int i = 0; i < n; i++) {
                low = min(low, matrix[i][0]);       // Smallest element (first of each row)
                high = max(high, matrix[i][m - 1]); // Largest element (last of each row)
            }
    
            int req = (n * m) / 2; // Required count of elements smaller than the median
    
            // Step 2: Binary search on value space
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int smallEqual = countSmallEqual(matrix, n, m, mid);
    
                if (smallEqual <= req) {
                    low = mid + 1; // Move right
                } else {
                    high = mid - 1; // Move left
                }
            }
    
            return low; // 'low' is the smallest number with more than half elements less than it → median
        }
    };
    

    //Brute force 

    // ✅ Intuition:
// We flatten the 2D matrix into a 1D list, sort it, and return the middle element.
// This works because the median is the middle value in a sorted list.

class Solution {
    public:
        int findMedian(vector<vector<int>>& matrix) {
            vector<int> ls;                        // To store all elements of the matrix
            int m = matrix.size();                 // Number of rows
            int n = matrix[0].size();              // Number of columns
    
            // ✅ Flattening the matrix into a 1D list
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    ls.push_back(matrix[i][j]);
                }
            }
    
            // ✅ Sorting the 1D list to get median
            sort(ls.begin(), ls.end());
    
            // ✅ Returning the median element
            return ls[(m * n) / 2];
        }
    };
    
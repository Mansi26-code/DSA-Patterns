// Given an n x n matrix, rotate it 90 degrees clockwise in-place.
// Do not return a new matrix in the optimal approach.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ✅ Approach 1: Transpose + Reverse Rows (Optimal In-place)
    // Time Complexity: O(n²)
    // Space Complexity: O(1)
    void rotateMatrix_TransposeReverse(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 🔹 Step 1: Transpose the matrix (swap across the diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 🔹 Step 2: Reverse each row to get the 90-degree rotated matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // ✅ Approach 2: Create a New Rotated Matrix (Uses Extra Space)
    // Time Complexity: O(n²)
    // Space Complexity: O(n²)
    void rotateMatrix_ExtraSpace(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n, 0));

        // 🔹 Fill rotated matrix with elements placed 90 degrees clockwise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        // 🔹 Copy rotated matrix back to original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rotated[i][j];
            }
        }
    }
};



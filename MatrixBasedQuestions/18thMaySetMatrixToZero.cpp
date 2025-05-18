// ✅ Problem: Set the entire row and column to 0 wherever a cell in the matrix is 0
// ✅ Approach: Store all positions of zeroes, then iterate to set respective rows and columns to 0

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();           // number of rows
            int n = matrix[0].size();        // number of columns
    
            vector<vector<int>> temp;        // to store the positions of all zeroes
    
            // 🔹 Step 1: Traverse the matrix and store positions of all 0s
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] == 0) {
                        temp.push_back({i, j});   // store row and column of 0
                    }
                }
            }
    
            // 🔹 Step 2: Set rows and columns to 0 based on the stored positions
            for(int i = 0; i < temp.size(); i++) {
                int row = temp[i][0];
                int col = temp[i][1];
    
                // Set entire row to 0
                for(int j = 0; j < n; j++) {
                    matrix[row][j] = 0;
                }
    
                // Set entire column to 0
                for(int k = 0; k < m; k++) {
                    matrix[k][col] = 0;
                }
            }
        }
    };
    
    /*
    🔍 Time Complexity: O(m × n) + O(K × (m + n)), where K = number of 0s
    🧠 Space Complexity: O(K), storing positions of all K zeroes
    Note:
    - This is a brute force approach that uses extra space to store all zero positions.
    - Efficient but not optimal for space — can be improved with in-place marking.
    */
    
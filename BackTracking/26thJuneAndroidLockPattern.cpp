// Given a 3x3 Android lock screen, count all valid unlock patterns of length between m and n, where:

// Dots can't repeat and must not jump over unvisited middle dots (like 1 → 3 requires 2 to be visited first).


class Solution {
public:
    int skip[10][10];     // skip[i][j] = middle key between i and j (if any)
    bool vis[10];         // visited array to mark visited keys

    // DFS to explore valid patterns starting from 'curr' with 'remaining' steps left
    int dfs(int curr, int remaining) {
        if (remaining == 0) return 1;

        vis[curr] = true;
        int count = 0;

        // Try all next possible keys
        for (int next = 1; next <= 9; ++next) {
            int middle = skip[curr][next];
            // Move only if 'next' is not visited and either there's no middle
            // or the middle dot is already visited
            if (!vis[next] && (middle == 0 || vis[middle])) {
                count += dfs(next, remaining - 1);
            }
        }

        vis[curr] = false; // backtrack
        return count;
    }

    int numberOfPatterns(int m, int n) {
        // Initialize skip array
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = 
        skip[4][6] = skip[6][4] = skip[2][8] = skip[8][2] = 5;

        int result = 0;
        for (int len = m; len <= n; ++len) {
            // Use symmetry:
            // 1,3,7,9 are symmetric → multiply result by 4
            result += 4 * dfs(1, len - 1);
            // 2,4,6,8 are symmetric → multiply result by 4
            result += 4 * dfs(2, len - 1);
            // 5 is unique (center)
            result += dfs(5, len - 1);
        }

        return result;
    }
};
Time Complexity: O(9 × 8!) (but effectively faster due to pruning & symmetry)

Space Complexity: O(1) (constant space) ✅
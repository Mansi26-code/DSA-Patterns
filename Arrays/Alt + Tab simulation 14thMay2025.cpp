/*
Given a list of open windows and a sequence of "Alt + Tab" actions (queries),
simulate the behavior of moving queried windows to the top in order and return the final order.
*/

class Solution {
    public:
        vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
            vector<int> ans;                    // Final order of windows after simulation
            unordered_set<int> seen;           // Tracks which windows have been moved to the top
    
            // Process the queries in reverse to prioritize the last move of each window
            for (int i = queries.size() - 1; i >= 0; i--) {
                int win = queries[i];
    
                // If window hasn't been moved yet, add it to the result and mark as moved
                if (seen.find(win) == seen.end()) {
                    ans.push_back(win);
                    seen.insert(win);
                }
            }
    
            // Add windows that weren't affected by queries, preserving their original order
            for (int i = 0; i < windows.size(); i++) {
                int win = windows[i];
    
                // If window was not moved via Alt+Tab, add it to the end
                if (seen.find(win) == seen.end()) {
                    ans.push_back(win);
                }
            }
    
            return ans;  // Final window order
        }
    };
    
    TC=O(m+n)
    SC=O(m)
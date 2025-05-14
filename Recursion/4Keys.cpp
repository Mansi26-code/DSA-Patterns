
Given n key presses, find the maximum number of 'A's you can print using keys: 'A', 'Ctrl-A', 'Ctrl-C', and 'Ctrl-V'.
Optimize the sequence of key presses to make the most efficient use of copy-paste operations.


//Recursive solution
class Solution {
    public:
        // Recursive helper function to find the maximum number of 'A's
        // n      -> remaining number of key presses
        // screen -> current number of 'A's on the screen
        // buffer -> last copied text (number of A's in buffer)
        int helper(int n, int screen, int buffer)
        {
            // Base case: No key presses left, return what's currently on screen
            if(n <= 0)
                return screen;
    
            // Option 1: Press 'A'
            // Use 1 key press to add one 'A' to screen
            int pressA = helper(n - 1, screen + 1, buffer);
    
            // Option 2: Press 'Ctrl-V'
            // Use 1 key press to paste buffer content onto the screen
            // Only useful if buffer has some content
            int paste = helper(n - 1, screen + buffer, buffer);
    
            // Option 3: Press 'Ctrl-A' + 'Ctrl-C' (takes 2 key presses)
            // Copy all content currently on screen to buffer
            // We don't change the screen yet, only buffer gets updated
            int copy = 0;
            if(n >= 2) {
                copy = helper(n - 2, screen, screen);
            }
    
            // Return the maximum number of A's that can be obtained from all options
            return max({pressA, copy, paste});
        }
    
        int maxA(int n) {
            // Entry point: no A's on screen and nothing in buffer initially
            return helper(n, 0, 0);
        }
    }; **TC= O(3^n)
       **SC= O(N)
    


    //Memoization 
    TC=O(n^2)
    SC= O(n)


    class Solution {
        public:
            int maxA(int n) {
                // Base case optimization: for n <= 5, best strategy is just pressing 'A' every time
                if (n <= 5)
                    return n;
        
                // Memoization table to store results of subproblems
                vector<int> dp(n + 1, -1);
        
                // Call helper to calculate max A's that can be printed with n key presses
                return helper(n, dp);
            }
        
        private:
            // Recursive helper function with memoization
            int helper(int n, vector<int>& dp) {
                // Again, if only 5 or fewer key presses left, just press 'A'
                if (n <= 5)
                    return n;
        
                // If this subproblem was already solved, return the stored result
                if (dp[n] != -1)
                    return dp[n];
        
                // Option 1: Press 'A' now → 1 A added + result of remaining (n-1) steps
                int result = helper(n - 1, dp) + 1;
        
                // Option 2: Try all possible copy-paste sequences
                // The idea is: Go back in time to where you last did a "Ctrl-A + Ctrl-C"
                // and then did "i" Ctrl-V operations from that copied value
                for (int i = 1; i <= 4; i++) {
                    // To perform Ctrl-A, Ctrl-C and i times Ctrl-V, we need (2 + i) steps in total
                    // So we go back (i + 2) steps from current n
                    if (n - i - 2 >= 1) {
                        // Multiply the value at that point by (i + 1) since we paste it (i) times
                        int current = helper(n - i - 2, dp) * (i + 1);
        
                        // Take the maximum between the result and this option
                        result = max(result, current);
                    }
                }
        
                // Save and return the result
                dp[n] = result;
                return result;
            }
        };
        
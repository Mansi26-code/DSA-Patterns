Given an array of integers, repeatedly increase local minima and decrease local maxima.
Return the final stable array where no element is strictly smaller or greater than both neighbors.


//BRUTE FORCE////

class Solution {
    public:
    
        // Function to check if the array is stable (no local peaks or valleys)
        bool isValid(vector<int>& arr) {
            for (int i = 1; i < arr.size() - 1; i++) {
                // If a local peak or valley is found, array is not yet stable
                if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
                    (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
                    return false;
                }
            }
            return true; // Array is stable
        }
    
        vector<int> transformArray(vector<int>& arr) {
            int n = arr.size();
    
            // Repeat the transformation until the array becomes stable
            while (!isValid(arr)) {
                vector<int> temp = arr;  // Copy of current state to apply changes safely
    
                for (int i = 1; i < n - 1; i++) {
                    // If current element is a local peak
                    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                        temp[i]--;
                    }
                    // If current element is a local valley
                    else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                        temp[i]++;
                    }
                }
    
                // Update original array with transformed values
                arr = temp;
            }
    
            return arr; // Final stable array
        }
    };
    

⏱️ Time Complexity
O(k × n) where

n = length of the array

k = number of rounds until stability (in worst case proportional to the maximum difference in the array, but typically small for random inputs)

💾 Space Complexity
O(n)

Additional temp array of size n each iteration

Recurring stack and the original array also take O(n)


//BETTER Approach

class Solution {
    public:
        vector<int> transformArray(vector<int>& arr) {
            int n = arr.size();
    
            // curr holds the current state of the array
            vector<int> curr = arr;
    
            // next will store the transformed state after one iteration
            vector<int> next = arr;
    
            while (true) {
                bool changed = false;  // To track if any changes occurred in this iteration
    
                // Traverse from second to second-last element
                for (int i = 1; i < n - 1; i++) {
    
                    // Check for local maxima (greater than both neighbors)
                    if (curr[i] > curr[i - 1] && curr[i] > curr[i + 1]) {
                        next[i] = curr[i] - 1;  // Decrease the element
                        changed = true;
                    }
    
                    // Check for local minima (less than both neighbors)
                    else if (curr[i] < curr[i - 1] && curr[i] < curr[i + 1]) {
                        next[i] = curr[i] + 1;  // Increase the element
                        changed = true;
                    }
    
                    // Otherwise, keep it unchanged
                    else {
                        next[i] = curr[i];
                    }
                }
    
                // If no element was changed, the array has stabilized
                if (!changed)
                    break;
    
                // Swap curr and next for next iteration
                swap(curr, next);
            }
    
            // Return the stabilized array
            return curr;
        }
    };
    

    🧠 Time Complexity:
O(k × n)
Where:

n = size of the array

k = number of iterations until the array stabilizes
In the worst case, each element might change several times (up to value difference with neighbors), but practically k is small (converges quickly).

📦 Space Complexity:
O(n)

curr and next vectors each take O(n) space.

No extra data structures apart from that.


//OPTIMAL Approach

class Solution {
    public:
        vector<int> transformArray(vector<int>& arr) {
            int n = arr.size();
    
            // If array has 2 or fewer elements, no transformation is needed
            if (n <= 2) return arr;
    
            while (true) {
                bool changed = false;
    
                // This array stores the amount of change for each element
                vector<int> updates(n, 0);
    
                // Check and mark local minima/maxima
                for (int i = 1; i < n - 1; i++) {
                    // If current element is smaller than both neighbors => local minimum
                    if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                        updates[i] = 1;  // Increase value
                        changed = true;
                    }
                    // If current element is greater than both neighbors => local maximum
                    else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                        updates[i] = -1;  // Decrease value
                        changed = true;
                    }
                }
    
                // If no element was updated, the array has stabilized
                if (!changed) break;
    
                // Apply the updates to the original array
                for (int i = 1; i < n - 1; i++) {
                    arr[i] += updates[i];
                }
            }
    
            return arr;  // Return the final stabilized array
        }
    };

    🧠 Time Complexity: O(k × n)
    📦 Space Complexity: O(n)
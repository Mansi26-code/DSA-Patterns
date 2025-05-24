class Solution {
    public:
        typedef long long ll;
    
        // Helper function to calculate the sum of decreasing elements starting from 'val - 1'
        // going down for 'count' steps. Formula used: val*count - (count*(count+1))/2
        ll getSumElements(ll count, ll val) {
            return val * count - (count * (count + 1)) / 2;
        }
    
        int maxValue(int n, int index, int maxSum) {
            int left = 1;             // Minimum possible value at 'index'
            int right = maxSum;       // Maximum possible value at 'index' (can't exceed total sum)
            ll mid_val;
            int result = 0;           // Variable to store the result
    
            // Binary search to find the maximum value we can place at nums[index]
            while (left <= right) {
                mid_val = left + (right - left) / 2;
    
                // Calculate sum of elements to the left of 'index'
                // The maximum number of decreasing elements on the left is min(index, mid_val - 1)
                ll left_count = min((ll)index, mid_val - 1);
                ll left_sum = getSumElements(left_count, mid_val);
    
                // Add 1s if there are more elements to the left than we can decrease
                left_sum += max((ll)0, index - mid_val + 1);
    
                // Calculate sum of elements to the right of 'index'
                // The maximum number of decreasing elements on the right is min(n - index - 1, mid_val - 1)
                ll right_count = min((ll)(n - index - 1), mid_val - 1);
                ll right_sum = getSumElements(right_count, mid_val);
    
                // Add 1s if there are more elements to the right than we can decrease
                right_sum += max((ll)0, (n - index - 1) - mid_val + 1);
    
                // Total sum is left_sum + right_sum + value at index (mid_val)
                if (left_sum + right_sum + mid_val <= maxSum) {
                    // If total sum is within allowed maxSum, this mid_val is a valid answer
                    result = max((ll)result, mid_val);
                    left = mid_val + 1; // Try for a higher value
                } else {
                    // If sum exceeds maxSum, try for a lower value
                    right = mid_val - 1;
                }
            }
    
            return result; // Final answer: maximum value that can be placed at nums[index]
        }
    };
    
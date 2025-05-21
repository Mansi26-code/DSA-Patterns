class Solution {
    public:
        // Function to find the number of times a sorted array has been rotated
        // This is the index of the minimum element in the array
        int findKRotation(vector<int>& arr) {
            int s = 0;
            int e = arr.size() - 1;
    
            // Binary search to locate the smallest element's index
            while (s < e) {
                int mid = s + (e - s) / 2;
    
                // If middle element is greater than the rightmost element,
                // the minimum must be in the right half
                if (arr[mid] > arr[e]) {
                    s = mid + 1;
                }
                // Otherwise, the minimum is in the left half (including mid)
                else {
                    e = mid;
                }
            }
    
            // 's' (or 'e') will be pointing to the index of the minimum element,
            // which is also the number of rotations
            return s;
        }
    };
    
class Solution {
    public:
        // Function to find the minimum element in a rotated sorted array
        int findMin(vector<int>& arr) {
            int s = 0;
            int e = arr.size() - 1;
    
            // Binary search loop to find the index of the minimum element
            while (s < e) {
                int mid = s + (e - s) / 2;
    
                // If mid element is greater than the rightmost element,
                // then the minimum lies in the right half
                if (arr[mid] > arr[e]) {
                    s = mid + 1;
                }
                // Else, the minimum lies in the left half (including mid)
                else {
                    e = mid;
                }
            }
    
            // When loop ends, 's' will be at the index of the minimum element
            return arr[s];
        }
    };

    
    //T.C=O(log n)
    //S.C=O(1)
class Solution {
    public:
        /*
        Find number of rotations in rotated sorted array.
    
        Approach:
        - Use binary search to find the index of minimum element.
        - If mid element is greater than end element, rotation is to the right side.
        - Else, rotation is on left side.
        - The start pointer will finally point to the minimum element.
        */
    
        int findKRotation(vector<int> &arr)  {
            int s = 0;
            int e = arr.size() - 1;
    
            while (s < e) {
                int mid = s + (e - s) / 2;
    
                // If mid element is greater than last element,
                // minimum must be to the right of mid
                if (arr[mid] > arr[e]) {
                    s = mid + 1;
                } else {
                    // minimum lies on left side including mid
                    e = mid;
                }
            }
    
            // s will point to the index of minimum element,
            // which is the count of rotations
            return s;
        }
    };
    
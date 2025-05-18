// 🧠 Problem: Merge two sorted arrays nums1 and nums2 into nums1 as one sorted array.
//            nums1 has a size of m + n, where the first m elements are initialized, and the rest are empty (0 or any value).
//            nums2 has n initialized elements.

// ✅ Approach 1: Optimal (Gap-style, In-place without extra space)
class Solution_Optimal {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // Start comparing from the end of initialized nums1 and start of nums2
            int left = m - 1;
            int right = 0;
    
            // Step 1: Swap larger elements from nums1 with smaller in nums2
            while (left >= 0 && right < n) {
                if (nums1[left] > nums2[right]) {
                    swap(nums1[left], nums2[right]);
                    left--;
                    right++;
                } else {
                    break;
                }
            }
    
            // Step 2: Sort both arrays individually
            sort(nums1.begin(), nums1.begin() + m);
            sort(nums2.begin(), nums2.end());
    
            // Step 3: Copy sorted nums2 into the empty space of nums1
            for (int i = m; i < m + n; i++) {
                nums1[i] = nums2[i - m];
            }
        }
    };
    
    // Time Complexity: O(m log m + n log n)
    // Space Complexity: O(1)
    
    // -------------------------------------------------------------
    
    // ✅ Approach 2: Better (Append + Sort using STL)
    class Solution_Better {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // Step 1: Append nums2 elements at the end of nums1
            for (int i = 0; i < n; i++) {
                nums1[i + m] = nums2[i];
            }
    
            // Step 2: Sort the entire nums1 array
            sort(nums1.begin(), nums1.end());
        }
    };
    
    // Time Complexity: O((m + n) log (m + n))
    // Space Complexity: O(1)
    
    // -------------------------------------------------------------
    
    // ✅ Approach 3: Brute Force (Using extra array to merge)
    class Solution_Brute {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int> merged(m + n); // Temporary array to store merged result
            int i = 0, j = 0, index = 0;
    
            // Step 1: Merge both arrays using two pointers
            while (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    merged[index++] = nums1[i++];
                } else {
                    merged[index++] = nums2[j++];
                }
            }
    
            // Step 2: Append remaining elements from nums1
            while (i < m) {
                merged[index++] = nums1[i++];
            }
    
            // Step 3: Append remaining elements from nums2
            while (j < n) {
                merged[index++] = nums2[j++];
            }
    
            // Step 4: Copy merged elements back to nums1
            for (int i = 0; i < m + n; i++) {
                nums1[i] = merged[i];
            }
        }
    };
    
    // Time Complexity: O(m + n)
    // Space Complexity: O(m + n) → uses extra space
    
    // -------------------------------------------------------------
    
    // ✅ How to use:
    // - Just instantiate the class you want to test:
    //      Solution_Optimal sol;
    //      sol.merge(nums1, m, nums2, n);
    
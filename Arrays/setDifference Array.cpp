//Given two sorted arrays nums1 and nums2, return an array containing the set difference of these two arrays.
//The result should include distinct values present in either of the arrays but not in both, and should be sorted in ascending order.

class Solution {
    public:
        vector<int> setDifference(vector<int>& nums1, vector<int>& nums2) {
            // Convert both arrays to sets to remove duplicates and allow efficient lookups
            set<int> st1(nums1.begin(), nums1.end());
            set<int> st2(nums2.begin(), nums2.end());
    
            vector<int> ans;
    
            // Find elements in st1 but not in st2
            for (int num : st1) {
                if (st2.find(num) == st2.end()) {
                    ans.push_back(num);
                }
            }
    
            // Find elements in st2 but not in st1
            for (int num : st2) {
                if (st1.find(num) == st1.end()) {
                    ans.push_back(num);
                }
            }
    
            // Sort the final answer (though sets are sorted, we sort in case of unordered containers or to ensure)
            sort(ans.begin(), ans.end());
    
            return ans;
        }
    };
    

    Time Complexity = O(n log n + m log m)
    Space Complexity = O(n + m)
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    // Approach 1: Using frequency map (Hash Map)
    // Time Complexity: O(m + n), where m = nums1.size(), n = nums2.size()
    // Space Complexity: O(m) for the frequency map
    vector<int> intersectionArray_Map(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> ans;

        // Count frequency of each element in nums1
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }

        // For each element in nums2, if present in map with count > 0,
        // add it to answer and decrement count to avoid duplicates
        for(int i = 0; i < nums2.size(); i++) {
            if(mp[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;
    }


    // Approach 2: Brute Force using visited array
    // Time Complexity: O(m * n) — nested loops over both arrays
    // Space Complexity: O(n) for visited array
    vector<int> intersectionArray_BruteForce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> visited(nums2.size(), 0);
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                // If element matches and nums2[j] is not visited
                if(nums1[i] == nums2[j] && visited[j] == 0) {
                    ans.push_back(nums2[j]);
                    visited[j] = 1;
                    break;
                }
                else if(nums2[j] > nums1[i]) {
                    // Since arrays are sorted, no need to check further
                    break;
                }
            }
        }
        return ans;
    }


    // Approach 3: Optimal two-pointer method
    // Time Complexity: O(m + n) — single pass through both sorted arrays
    // Space Complexity: O(1) ignoring output array
    vector<int> intersectionArray_TwoPointer(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        vector<int> ans;

        while(i < m && j < n) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};

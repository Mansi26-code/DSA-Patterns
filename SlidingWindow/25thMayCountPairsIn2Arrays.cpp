




//Brute Force
//Time: O(n^2)

//Space: O(n)

class Solution {
public:
    int countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int count = 0;

        // Step 1: Compute the diff array
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = nums1[i] - nums2[i];
        }

        // Step 2: Check all pairs (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (diff[i] + diff[j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


class Solution {
public:
    int countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int count = 0;

        // Step 1: Compute the diff array
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = nums1[i] - nums2[i];
        }

        // Step 2: Sort the diff array
        sort(diff.begin(), diff.end());

        // Step 3: Two-pointer technique
        int i = 0, j = n - 1;
        while (i < j) {
            if (diff[i] + diff[j] > 0) {
                // All indices between i and j (exclusive) will also form valid pairs with j
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }

        return count;
    }
};

// Time: O(n log n) (due to sorting)

// Space: O(n) (for the diff array)
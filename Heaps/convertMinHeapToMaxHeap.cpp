class Solution {
   public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        return nums;
    }
};


Time Complexity:O(n), where n is the number of elements in the input vector. Building a heap takes O(n) time, and the heapify operation has a time complexity of O(log n). Since heapify is called approximately n/2 times in the loop, the overall time complexity becomes O(n).
Space Complexity:O(1), The algorithm operates in place with a few extra variables, resulting in constant space complexity.
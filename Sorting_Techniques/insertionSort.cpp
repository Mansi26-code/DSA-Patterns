class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();

        // Start from the second element (index 1) and insert it into the sorted part
        for (int i = 1; i < n; i++) {
            int key = nums[i];       // Element to be placed at the correct position
            int j = i - 1;

            // Move elements of nums[0..i-1], that are greater than key, one position ahead
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j]; // Shift larger elements to the right
                j--;
            }

            // Place the key at its correct sorted position
            nums[j + 1] = key;
        }

        return nums;
    }
};



//recursive

class Solution {
public:

    // Recursive function to sort first 'n' elements
    void recursiveInsertionSort(vector<int>& nums, int n) {
        // Base case: when array size is 1 or less, it's already sorted
        if (n <= 1)
            return;

        // Recursively sort the first (n-1) elements
        recursiveInsertionSort(nums, n - 1);

        // Now insert the nth element (nums[n-1]) into the sorted array of size (n-1)
        int key = nums[n - 1];
        int j = n - 2;

        // Shift elements greater than key one position to the right
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        // Place the key in its correct sorted position
        nums[j + 1] = key;
    }

    // Function to sort using recursive insertion sort
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();

        // Call the recursive function
        recursiveInsertionSort(nums, n);

        return nums;
    }
};
| Scenario         | Complexity | Explanation                                                                                                                 |
| ---------------- | ---------- | --------------------------------------------------------------------------------------------------------------------------- |
| **Best Case**    | **O(n)**   | When the array is already sorted, the inner `while` loop doesn't run much. So, we do only `n - 1` comparisons, no shifts.   |
| **Average Case** | **O(n²)**  | On average, each element might need to be compared with half of the already sorted part → sum of `1 + 2 + ... + n = O(n²)`. |
| **Worst Case**   | **O(n²)**  | When the array is sorted in reverse, every new element has to be compared and moved all the way to the beginning.           |



//recursive tc sc 


| Scenario         | Complexity | Explanation                                                                                                                       |
| ---------------- | ---------- | --------------------------------------------------------------------------------------------------------------------------------- |
| **Best Case**    | **O(n)**   | When the array is already sorted, the inner `while` loop rarely runs. But recursive calls still go up to size `n`, so still O(n). |
| **Average Case** | **O(n²)**  | Each recursive level (total of `n`) can have up to `n` comparisons in the worst case within the inner loop.                       |
| **Worst Case**   | **O(n²)**  | Like in iterative, if the array is in descending order, every element must shift back, and recursion still goes deep to `n`.      |

class Solution {
    public:
        /*
        Helper function to check if allocation is possible:
        - nums: array of pages
        - m: number of students
        - mid: maximum allowed pages for a student
        
        Returns true if it's possible to allocate books so that
        no student reads more than mid pages.
        */
        bool isPossible(vector<int>& nums, int m, int mid) {
            int students = 1;  // start with first student
            int pages = 0;     // pages assigned to current student
    
            for (int i = 0; i < nums.size(); i++) {
                // If a single book has more pages than mid, allocation impossible
                if (nums[i] > mid) return false;
    
                if (pages + nums[i] <= mid) {
                    pages += nums[i];  // assign book to current student
                } else {
                    // allocate next student
                    students++;
                    pages = nums[i];
                    // If students required exceed m, not possible
                    if (students > m)
                        return false;
                }
            }
            return true;
        }
    
        /*
        Allocate Minimum Number of Pages Problem:
    
        - Binary search on answer space (maximum pages).
        - Use isPossible to validate the mid.
        */
        int findPages(vector<int>& nums, int m) {
            int n = nums.size();
            // If students more than books, not possible
            if (n < m) return -1;
    
            int s = 0;
            int e = accumulate(nums.begin(), nums.end(), 0);  // sum of all pages
            int ans = -1;
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (isPossible(nums, m, mid)) {
                    ans = mid;      // valid allocation found
                    e = mid - 1;    // try to minimize maximum pages
                } else {
                    s = mid + 1;    // increase allowed pages
                }
            }
    
            return ans;
        }
    };
    
class Solution {
public:
    bool isHeap(vector<int>& nums) {
       
       int n=nums.size();
       for(int i=0;i<n/2;i++)
       {
        if(2*i+1<n)
        {
            if(nums[i]>nums[2*i+1])
            {
                return false;
            }
        }
        if(2*i+2<n)
        {
            if(nums[i]>nums[2*i+2])
            {
                return false;
            }
        }
       }
       return true;
    }
};

Time Complexity:The time complexity is O(n) because the code iterates through approximately half the elements of the input vector 'nums' in the worst case.
Space Complexity:The space complexity is O(1) because the code uses a constant amount of extra space, regardless of the input size.
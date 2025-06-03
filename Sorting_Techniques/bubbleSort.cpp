class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            bool isSwapped=false;
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    isSwapped=true;
                }
            }
            if(!isSwapped)
            break;
        }
        return nums;
    }
};


// Time Complexity:The time complexity is O(n^2) in the worst and average case, and O(n) in the best case due to the early termination optimization.
// Space Complexity:The space complexity is O(1) as it sorts the array in-place.


//Recursive BubbleSort


class Solution {
public:

void RecursiveBubbleSort(vector<int>&nums, int n)
{
    if (n == 1)
        return;
    for(int i=0;i<n-1;i++)
    {
         if( nums[i]>nums[i+1])
         {
            swap(nums[i],nums[i+1]);
         }
    }
    RecursiveBubbleSort(nums,n-1);
}
    vector<int> bubbleSort(vector<int>& nums) {
          int n=nums.size();
          RecursiveBubbleSort(nums,n);
          return nums;
    }
};


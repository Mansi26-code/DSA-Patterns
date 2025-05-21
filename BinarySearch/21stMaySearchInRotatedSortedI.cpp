class Solution {
    public:
    int pivot(vector<int>&nums)
    {
      int s=0, e=nums.size()-1;
      while(s<e)
      {
        int mid=s+(e-s)/2;
        if(nums[s]<=nums[e])
        return s;
        if(nums[mid]>nums[e])
        {
            s=mid+1;
        }
        else
        e=mid;
      }
      return s;
    }
    
    int binarySearch(vector<int>&nums, int s, int e, int x)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==x)
            return mid;
    
            else if(nums[mid]<x)
            s=mid+1;
    
            else
            e=mid-1;
        }
        return -1;
    }
        int search(vector<int>& nums, int target) {
            int pivott=pivot(nums);
            cout<<pivott;
            int left=-1,right=-1;
            left=binarySearch(nums, 0, pivott-1, target);
            if(left!=-1)return left;
    
          
            return binarySearch(nums, pivott,nums.size()-1,target);
        }
    };
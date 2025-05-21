class Solution {
    public:
    
    int floor(vector<int>&nums, int x)
    {
        int n=nums.size();
        int ans=-1;
        int s=0, e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<=x)
            {
                ans=nums[mid];
                s=mid+1;
            }
            
            else {
                e=mid-1;
            }
        }
        return ans;
    }
    
    
    int ceil(vector<int>&nums, int x)
    {
        int n=nums.size();
        int ans=-1;
        int s=0, e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=x)
            {
                ans=nums[mid];
                e=mid-1;
            }
             else{
                s=mid+1;
            }
            
        }
        return ans;
    }
        vector<int> getFloorAndCeil(vector<int> nums, int x) {
       vector<int>ans;
       ans.push_back(floor(nums, x));
       ans.push_back(ceil(nums,x));
       return ans;
        }
    };
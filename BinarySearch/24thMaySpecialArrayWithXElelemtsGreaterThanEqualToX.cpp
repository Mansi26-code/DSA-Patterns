class Solution {
    public:
    
        int specialArray(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int s=0, e=nums.size();
            int ans=-1;
            while(s<=e)
            {
                  int mid=s+(e-s)/2;
                int count=0;
              
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]>=mid)
                    {
                        count++;
                    }
                }
                    if(count==mid)
                    {
                         ans=mid;
                         break;
                    }
                    else if(count>mid)
                    {
                       
                        s=mid+1;
                    }
                    else
                    {
                       
                        e=mid-1;
                    }
                   
                
            }
            return ans;
        }
    };
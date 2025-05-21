class Solution {
    public:
      int smallestDivisor(vector<int> &nums, int limit) {
           int s=1;
           int e= *max_element(nums.begin(),nums.end());
           
           int ans=1;
           while(s<=e)
           {
            int mid=s+(e-s)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
              sum+=(ceil)((double)nums[i]/mid);
            }
            if(sum<=limit)
            {
              ans=mid;
              e=mid-1;
            }
            else{
             s=mid+1;
            }
           }
           return ans;
        }
    };
class Solution {
    public:
        int minSpeedOnTime(vector<int>& dist, double hour) {
            int s=1;
            int e=1e7;
         
            int ans=-1;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                   double time=0.0;
        
                for(int i=0;i<dist.size()-1;i++)
                {
                  time+=(ceil)((double)dist[i]/mid);
    
                }
                time+=(double)(dist[dist.size()-1])/mid;
    
                if(time<=hour)
                {
                    ans=mid;
                    e=mid-1;
                }
                else
                {
                   s=mid+1;
                }
            }
            return ans;
        }
    };
class Solution {
    public:
        long long minimumTime(vector<int>& time, int totalTrips) {
           long long s=1;
            long long e=(long long)*max_element(time.begin(), time.end()) * (long long)totalTrips;
    
           
            while(s<=e)
            {
               long long mid=s+(e-s)/2;
               long long currTrip=0;
                for(int i=0;i<time.size();i++)
                {
                    currTrip+=mid/time[i];
    
                }
                if(currTrip<totalTrips)
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            return s;
        }
    };
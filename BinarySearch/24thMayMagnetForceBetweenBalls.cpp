class Solution {
    public:
    bool isPossible(vector<int>&position, int mid, int m)
    {
        int count=1;
        int lastPos=position[0];
        int n=position.size();
        for(int i=1;i<n;i++)
        {
            if(position[i]-lastPos>=mid)
            {
                count++;
                lastPos=position[i];
            }
    
        }
        return count>=m;
    
    }
        int maxDistance(vector<int>& position, int m) {
            sort(position.begin(),position.end());
            int s=1;
            int n=position.size();
            int e=position[n-1]-position[0];
            int ans=0;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(isPossible(position,mid,m))
                {
                    ans=mid;
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
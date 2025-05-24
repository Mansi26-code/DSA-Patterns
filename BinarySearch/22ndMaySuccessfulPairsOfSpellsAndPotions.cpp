class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
           
            sort(potions.begin(), potions.end());
            vector<int>ans;
    
            int n=spells.size();
            int m=potions.size();
            
           
                for(int i=0;i<n;i++)
                {
                    int s=0;int e=m-1;
                    int idx=m;
                    
                     while(s<=e)
            {
                int mid=s+(e-s)/2;
                   if ((long long)spells[i] * (long long)potions[mid] >= success)
    
    
                    {
                        idx=mid;
                        e=mid-1;
                       
                    }
                    else 
                    {
                        s=mid+1;
                    }
                  
                }
                ans.push_back(m-idx);
            }
            return ans;
        }
    };
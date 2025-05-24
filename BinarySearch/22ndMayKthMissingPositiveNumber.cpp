//Brute using maps  TC= O(N+K)

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            unordered_map<int,int>mp;
            for(int num:arr)
            {
                mp[num]++;
            }
            vector<int>temp;
            for(int i=1; ; i++)
            {
                if(mp.find(i)==mp.end())
                {
                    temp.push_back(i);
                    if(temp.size()==k)
                    return temp[k-1];
                }
            }
            return -1;
        }
    };

//Optimal using binary Search TC=O(log n)

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int s=0, e=arr.size()-1;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                int missingTillEnd=arr[mid]-(mid+1);
    
                if(missingTillEnd<k)
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            return s+k;
        }
    };
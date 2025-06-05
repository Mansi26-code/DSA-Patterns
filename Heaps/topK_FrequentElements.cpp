class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
 for(auto i=mp.begin();i!=mp.end();i++)
 {
    minHeap.push({i->second, i->first});

    while(minHeap.size()>k)
    {
        minHeap.pop();
    }
 }

 vector<int>ans;
 while(!minHeap.empty())
 {
    ans.push_back(minHeap.top().second);
    minHeap.pop();
 }
 return ans;

    }
};

✅ Summary
Time Complexity: O(N log K)

Space Complexity: O(N)
class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        int n=val.size();
        vector<pair<long long,long long>>knapSack;

        for(int i=0;i<n;i++)
        {
            knapSack.push_back({val[i],wt[i]});
        }

        sort(knapSack.begin(),knapSack.end(),[](const pair<long long, long long>&a, const pair<long long,long long>&b){
            double r1=(double)a.first/a.second;
            double r2=(double)b.first/b.second;

            return r1>r2;
        });

        double ans=0.0;
        double remaining=capacity;
        for(int i=0;i<n && remaining>0;i++)
        {
            long long itemWt=knapSack[i].second;
            long long itemValue=knapSack[i].first;

            if(itemWt<=remaining)
            {
                ans+=itemValue;
                remaining-=itemWt;
            }
            else
            {
                ans+=(double)itemValue*remaining/itemWt;
                remaining=0;
            }
        }
        return ans;

    }
};

Time Complexity:O(n log n)
Space Complexity:O(n)
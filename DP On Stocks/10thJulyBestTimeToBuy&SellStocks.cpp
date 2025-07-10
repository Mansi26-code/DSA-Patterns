class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int cp=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            maxprofit=max(maxprofit,prices[i]-cp);
            cp=min(cp,prices[i]);
        }
        return maxprofit;
    }
};

//TC=O(N)
//SC=O(1)
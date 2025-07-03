class Solution {
   public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        // your code goes here
        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int platform = 1;
        int maxPlatform = 1;
        int i = 1, j = 0;
        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                platform++;
                i++;
            } else {
                platform--;

                j++;
            }
            maxPlatform = max(maxPlatform, platform);
        }
        return maxPlatform;
    }
};


//TC=O(nlogn)
//SC=O(1)
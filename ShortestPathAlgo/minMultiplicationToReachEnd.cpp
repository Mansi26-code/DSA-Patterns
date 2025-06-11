class Solution {
   public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        // agar start end k equal h to 0 return kro
        if (start == end) return 0;
        int mod = 100000;
        vector<int> dist(1000000, 1e9);
        queue<pair<int, int>> q;
        dist[start] = 0;
        q.push({start, 0});  // its storing in the form of node and steps

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for (auto &it : arr) {
                int num = (node * it) % mod;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;

                    if (num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};


Time Complexity:O(100000 * N)
Space Complexity:O(100000) 
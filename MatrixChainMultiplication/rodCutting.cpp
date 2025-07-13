class Solution {
public:

// Recursive function to find minimum cost of cuts between cuts[i] and cuts[j]
int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp)
{
    // Base case: No space between i and j (no cuts possible)
    if(i + 1 == j)
        return 0;

    // Memoization check
    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // Loop over all possible cuts between i and j
    // k = i+1 to j-1 because:
    // - cuts[i] is segment start (can't cut here)
    // - cuts[j] is segment end (can't cut here)
    for(int k = i + 1; k < j; k++)
    {
        // Recursive cost:
        // left segment = cuts[i] to cuts[k]
        // right segment = cuts[k] to cuts[j]
        // + cost to cut current segment = cuts[j] - cuts[i]
        int ans = solve(cuts, i, k, dp) + solve(cuts, k, j, dp) + cuts[j] - cuts[i];

        mini = min(mini, ans);
    }
    // Store and return minimum cost
    return dp[i][j] = mini;
}

int minCost(int n, vector<int>& cuts) {
    // Why push 0 and n?
    // Because stick is from 0 to n, these are segment boundaries
    cuts.push_back(0);
    cuts.push_back(n);

    // Sorting to ensure all cuts are in order
    sort(cuts.begin(), cuts.end());

    int c = cuts.size();
    // dp[i][j] stores min cost to cut segment cuts[i] to cuts[j]
    vector<vector<int>> dp(c, vector<int>(c, -1));

    // Start solving for the full stick segment: cuts[0] to cuts[c-1]
    return solve(cuts, 0, c - 1, dp);
}
};


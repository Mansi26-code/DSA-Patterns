// Brute Force Approach
// For each worker, check every job and assign the highest profit job they can do
class Solution {
    public:
        int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
            int totalProfit = 0;
    
            // Loop through each worker
            for (int i = 0; i < worker.size(); i++) {
                int maxProfit = 0;
    
                // Check all jobs for this worker
                for (int j = 0; j < difficulty.size(); j++) {
                    // If worker can do the job (skill >= difficulty)
                    if (worker[i] >= difficulty[j]) {
                        // Take the maximum profit they can get
                        maxProfit = max(maxProfit, profit[j]);
                    }
                }
    
                // Add that profit to the total
                totalProfit += maxProfit;
            }
    
            return totalProfit;
        }
    };
    


    // Optimized Approach
// Step 1: Pair each job's difficulty with its profit
// Step 2: Sort jobs by difficulty and preprocess max profit so far
// Step 3: For each worker, binary search the best job they can do

class Solution {
    public:
        int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
            vector<pair<int, int>> difProf;
    
            // Step 1: Pair each job as (difficulty, profit)
            for (int i = 0; i < difficulty.size(); i++) {
                difProf.push_back({difficulty[i], profit[i]});
            }
    
            // Step 2: Sort jobs by difficulty
            sort(difProf.begin(), difProf.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });
    
            // Step 3: Preprocess to make profit non-decreasing
            // At each difficulty, store the maximum profit seen so far
            for (int i = 1; i < difProf.size(); i++) {
                difProf[i].second = max(difProf[i].second, difProf[i - 1].second);
            }
    
            // Step 4: Sort workers by skill
            sort(worker.begin(), worker.end());
    
            int totalProfit = 0;
    
            // Step 5: For each worker, binary search best job they can do
            for (int j = 0; j < worker.size(); j++) {
                int s = 0, e = difProf.size() - 1;
                int maxProfit = 0;
    
                while (s <= e) {
                    int mid = s + (e - s) / 2;
    
                    // If worker can do this job
                    if (worker[j] >= difProf[mid].first) {
                        maxProfit = difProf[mid].second;  // max profit at this level
                        s = mid + 1;  // search in right half
                    } else {
                        e = mid - 1;  // search in left half
                    }
                }
    
                // Add best profit for this worker
                totalProfit += maxProfit;
            }
    
            return totalProfit;
        }
    };
    
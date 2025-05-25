/*
🔹 Diet Plan Performance (Leetcode 1176)
You are given an array of calories and a window size k. Calculate total points by:
- Adding 1 if sum of k-day calories > upper
- Subtracting 1 if sum < lower
- 0 if sum lies between [lower, upper]

------------------------------------------
Brute Force Approach – Time: O(n*k), Space: O(1)
------------------------------------------
*/

class BruteForceSolution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int points = 0;

        // Traverse all possible subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            int T = 0;

            // Calculate sum of k-day window starting at index i
            for (int j = i; j < i + k; j++) {
                T += calories[j];
            }

            // Update points based on T
            if (T < lower)
                points--;
            else if (T > upper)
                points++;
            // If in range [lower, upper], points += 0 (do nothing)
        }

        return points;
    }
};


/*
------------------------------------------
Optimized Sliding Window – Time: O(n), Space: O(1)
------------------------------------------
*/

class OptimizedSolution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int points = 0;
        int T = 0;

        // Initial sum of first k days
        for (int i = 0; i < k; i++) {
            T += calories[i];
        }

        // Evaluate the first window
        if (T < lower)
            points--;
        else if (T > upper)
            points++;

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            // Add next element and remove the oldest
            T += calories[i] - calories[i - k];

            // Evaluate window
            if (T < lower)
                points--;
            else if (T > upper)
                points++;
        }

        return points;
    }
};

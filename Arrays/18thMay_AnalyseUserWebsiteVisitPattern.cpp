/*
Leetcode 1152: Most Visited Pattern
-------------------------------------
Given visit data of users (username, timestamp, website), find the 3-website pattern visited by the most users.
If multiple patterns have the same count, return the lexicographically smallest one.
*/

class Solution {
    public:
        vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
            int n = username.size();
    
            // Step 1: Combine all data into one vector and sort it by timestamp
            vector<tuple<int, string, string>> data;
            for (int i = 0; i < n; i++) {
                data.emplace_back(timestamp[i], username[i], website[i]);
            }
            sort(data.begin(), data.end());  // Sorting to maintain chronological visit order
    
            // Step 2: Build user → websites visited (in sorted order of time)
            unordered_map<string, vector<string>> userVisits;
            for (auto& [time, user, site] : data) {
                userVisits[user].push_back(site);
            }
    
            // Step 3: For each user, collect all unique 3-sequence patterns
            map<vector<string>, set<string>> patternUsers;
            for (auto& [user, sites] : userVisits) {
                if (sites.size() < 3) continue;  // Can't form a 3-sequence
    
                set<vector<string>> uniquePatterns;
    
                // Generate all combinations of 3-website sequences for a user
                for (int i = 0; i < sites.size(); i++) {
                    for (int j = i + 1; j < sites.size(); j++) {
                        for (int k = j + 1; k < sites.size(); k++) {
                            uniquePatterns.insert({sites[i], sites[j], sites[k]});
                        }
                    }
                }
    
                // Add user to each of their 3-patterns in patternUsers
                for (auto& pattern : uniquePatterns) {
                    patternUsers[pattern].insert(user);
                }
            }
    
            // Step 4: Find the pattern with the highest user count
            int maxCount = 0;
            vector<string> result;
    
            for (auto& [pattern, users] : patternUsers) {
                // Choose pattern with:
                // - more unique users, or
                // - same number of users but lexicographically smaller
                if ((int)users.size() > maxCount || 
                    ((int)users.size() == maxCount && pattern < result)) {
                    maxCount = users.size();
                    result = pattern;
                }
            }
    
            return result;
        }
    };

    
    /*
🔍 Dry Run:

Input:
username  = ["u1", "u1", "u1", "u2", "u2", "u2"]
timestamp = [1, 2, 3, 4, 5, 6]
website   = ["a", "b", "c", "a", "b", "a"]

1️⃣ After combining & sorting by timestamp:
data = [
  (1, "u1", "a"),
  (2, "u1", "b"),
  (3, "u1", "c"),
  (4, "u2", "a"),
  (5, "u2", "b"),
  (6, "u2", "a")
]

2️⃣ Build userVisits:
userVisits = {
  "u1": ["a", "b", "c"],
  "u2": ["a", "b", "a"]
}

3️⃣ Build all 3-sequence patterns:

For u1:
→ Possible combinations of 3 sites:
   ["a", "b", "c"]
   (Only 1 combination as there are exactly 3 sites)

→ Add to patternUsers:
patternUsers[["a", "b", "c"]] = {"u1"}

For u2:
→ All unique combinations of 3 sites:
   i=0, j=1, k=2 → ["a", "b", "a"]
→ Add to patternUsers:
patternUsers[["a", "b", "a"]] = {"u2"}

Final patternUsers map:
{
  ["a", "b", "c"]: {"u1"},
  ["a", "b", "a"]: {"u2"}
}

4️⃣ Find the most visited pattern:

- Both patterns visited by 1 unique user
- Tie-break by lexicographical order

→ Compare:
  ["a", "b", "a"] < ["a", "b", "c"] ✅

✅ Result = ["a", "b", "a"]
*/

class DisjointSet {
public:
    vector<int> parent, rank;

    // Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find function with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank to attach smaller tree under bigger one
    void UnionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return; // Already in the same set

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n); // Disjoint set to group accounts by index

        unordered_map<string, int> emailToIndex;   // Maps email to the account index (first time it appeared)
        unordered_map<string, string> emailToName; // Maps email to corresponding name

        // Step 1: Build the DSU using common emails
        for (int i = 0; i < n; i++) {
            string name = accounts[i][0]; // Name is at 0th index
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                emailToName[email] = name; // Map email to name

                if (emailToIndex.find(email) == emailToIndex.end()) {
                    // First time seeing this email, store its index
                    emailToIndex[email] = i;
                } else {
                    // Email already exists, union the two account indices
                    ds.UnionByRank(i, emailToIndex[email]);
                }
            }
        }

        // Step 2: Group emails by their parent index
        unordered_map<int, vector<string>> mergedEmails;
        for (auto& [email, idx] : emailToIndex) {
            int parent = ds.findUPar(idx);
            mergedEmails[parent].push_back(email);
        }

        // Step 3: Build the result vector
        vector<vector<string>> result;
        for (auto& [idx, emails] : mergedEmails) {
            sort(emails.begin(), emails.end());                  // Sort the emails
            string name = emailToName[emails[0]];                // Get name from any email (same for all)
            emails.insert(emails.begin(), name);                 // Insert name at the start
            result.push_back(emails);                            // Push the final merged account
        }

        return result;
    }
};

// ✅ Time Complexity: O(N * M + K + E)
// N = number of words, M = avg word length, K = number of distinct characters
// E = number of edges formed by character precedence relations
//
// ✅ Space Complexity: O(K + E) => for adjacency list, inDegree array, result

class Solution {
public:

    // Function to perform Kahn's Topological Sort
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0); // To store indegree of each node (character)

        // Count indegrees
        for (int i = 0; i < V; i++) {
            for (auto &it : adj[i]) {
                inDegree[it]++;
            }
        }

        // Push nodes with 0 indegree into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo; // Result of topological sort

        // Standard Kahn's BFS-based Topo Sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto &it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

    // Main function to determine the character order from dictionary
    string findOrder(string dict[], int N, int K) {
        // Create adjacency list for graph with K characters
        vector<int> adj[K];

        // Step 1: Build the graph by comparing adjacent words
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            // Compare characters of the two words
            for (int ptr = 0; ptr < len; ptr++) {
                // As soon as characters differ, we can establish a relation
                if (s1[ptr] != s2[ptr]) {
                    int u = s1[ptr] - 'a'; // Convert char to index
                    int v = s2[ptr] - 'a';
                    adj[u].push_back(v); // u -> v means u comes before v
                    break; // Only the first difference matters
                }
            }
        }

        // Step 2: Perform Topological Sort on the graph
        vector<int> topo = topoSort(K, adj);

        // Step 3: Convert topological order from indices to characters
        string ans = "";
        for (int i = 0; i < K; i++) {
            ans.push_back('a' + topo[i]); // Convert index back to character
        }

        return ans;
    }
};

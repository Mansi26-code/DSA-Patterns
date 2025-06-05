// C++ program to determine if it's possible to finish all courses
// using Kahn's Algorithm (BFS-based Topological Sort)

class Solution {
public:
    /**
     * @brief Checks if all courses can be finished given prerequisites.
     *
     * @param numCourses Total number of courses (vertices).
     * @param prerequisites List of prerequisite pairs [u, v] meaning v -> u.
     * @return true if all courses can be finished (i.e., graph is acyclic), false otherwise.
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;

        vector<vector<int>> adj(N);      // Adjacency list for the graph
        vector<int> inDegree(N, 0);      // Stores in-degree for each course

        // Step 1: Build the adjacency list from prerequisites
        for (auto &it : prerequisites) {
            int u = it[0]; // Course u
            int v = it[1]; // Prerequisite v for course u
            adj[v].push_back(u); // Edge from v to u
        }

        // Step 2: Compute in-degrees
        for (int i = 0; i < N; i++) {
            for (auto &it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;

        // Step 3: Push courses with in-degree 0 (no prerequisites)
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0; // Count of courses that can be finished

        // Step 4: Perform BFS to simulate course completion
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completed++;

            for (auto &next : adj[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Step 5: If all courses are completed, return true
        return completed == N;
    }
};


📊 Time and Space Complexity:
Time Complexity: O(V + E)

V = number of courses

E = number of prerequisite pairs

Space Complexity: O(V + E)

For adjacency list, in-degree array, and queue
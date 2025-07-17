#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) with Union by Rank
class DisjointSet {
public:
    vector<int> parent, rank;

    // Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Initially, each element is its own parent
        }
    }

    // Find operation with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank: attach smaller rank tree under larger rank tree
    void UnionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;  // Already in same set

        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet dsu(n);

        // Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If same row or same column, connect them
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dsu.UnionByRank(i, j);
                }
            }
        }

        // Count how many groups (unique parents) are there
        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findUPar(i) == i) {
                groups++;
            }
        }

        // Maximum stones we can remove = total stones - number of groups
        return n - groups;
    }
};

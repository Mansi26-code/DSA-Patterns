class Solution {
   public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }

        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }

        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int maxRemove(vector<vector<int>>& stones, int n) {
        int components = n;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                    unionSet(i, j);
            }
        }

        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) groups++;
        }

        return n - groups;
    }
};
class Disjoint {
   public:
    vector<int> parent, size;
    Disjoint(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        size.resize(n, 1);
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void connect(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv) return;

        if (size[pu] <= size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint d(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (d.findUltimateParent(u) == d.findUltimateParent(v)) return edge;

            d.connect(u, v);
        }

        return {};
    }
};

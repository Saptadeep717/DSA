class Disjoint {
public:
    vector<int> parent, sizeArray;
    Disjoint(int n) {
        parent.resize(n);
        sizeArray.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int u) {
        if (parent[u] == u)
            return u;
        else
            return parent[u] = findUltimateParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ulP_u = findUltimateParent(u);
        int ulP_v = findUltimateParent(v);

        if (ulP_u == ulP_v)
            return;

        if (sizeArray[ulP_u] < sizeArray[ulP_v]) {
            parent[ulP_u] = ulP_v;
            sizeArray[ulP_v] += sizeArray[ulP_u];
        } else {
            parent[ulP_v] = ulP_u;
            sizeArray[ulP_u] += sizeArray[ulP_v];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        Disjoint ds(n);

        for (int i = 0; i < edges.size(); i++) {
            vector<int>& vec = edges[i];
            ds.unionBySize(vec[0], vec[1]);
        }

        unordered_map<int, long long> comp;

        for (int i = 0; i < n; i++) {
            comp[ds.findUltimateParent(i)]++;
        }

        long long ans = 0, sum = 0;
        for (auto& p : comp) {
            ans += p.second * sum;
            sum += p.second;
        }

        return ans;
    }
};
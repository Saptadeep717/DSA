class Disjoint {
public:
    vector<int> parent, sizeA;
    Disjoint(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltiParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUltiParent(parent[u]);
    }

    void connect(int u, int v) {
        int pu = findUltiParent(u);
        int pv = findUltiParent(v);

        if (pu == pv) return;

        if (pu < pv)
            parent[pv] = pu;
        else
            parent[pu] = pv;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        Disjoint ds(26);
        for (int i = 0; i < n; i++) {
            ds.connect(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < 26; i++) {
            cout << char(ds.parent[i] + 'a') << " ";
        }
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
            ans += char(ds.findUltiParent(baseStr[i] - 'a') + 'a');
        }
        return ans;
    }
};
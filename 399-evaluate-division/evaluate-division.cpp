using P = pair<string, double>;
class Solution {
public:
    double bfs(string& s, string& e, unordered_map<string, vector<P>>& adj) {
        unordered_set<string> vis;
        vis.insert(s);
        queue<P> q;
        q.push({s, 1.0});

        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();
            if (node == e)
                return val;
            for (auto& it : adj[node]) {
                if (!vis.count(it.first)) {
                    vis.insert(it.first);
                    q.push({it.first, val * it.second});
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<P>> adj;
        vector<double> ans;
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.00 / values[i]});
        }

        for (int i = 0; i < queries.size(); i++) {
            string v1 = queries[i][0], v2 = queries[i][1];
            if (!adj.count(v1) || !adj.count(v2)) {
                ans.push_back(-1.0);
                continue;
            }
            if (v1 == v2) {
                ans.push_back(1.0);
                continue;
            }

            double val = bfs(v1, v2, adj);
            ans.push_back(val);
        }

        return ans;
    }
};
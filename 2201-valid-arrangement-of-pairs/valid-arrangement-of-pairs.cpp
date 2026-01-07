class Solution {
public:
    void eulerTour(int node, unordered_map<int, vector<int>>& adj,
                   vector<int>& path) {
        while (!adj[node].empty()) {
            int v = adj[node].back();
            adj[node].pop_back();
            eulerTour(v, adj, path);
        }
        path.push_back(node);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int startNode = pairs[0][0];
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        vector<int> path;
        for (int i = 0; i < n; i++) {
            vector<int>& p = pairs[i];
            int u = p[0], v = p[1];
            // u-->v
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        for (auto& it : adj) {
            int node = it.first;

            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        eulerTour(startNode, adj, path);

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;

        for (int i = 0; i < path.size() - 1; i++) {
            ans.push_back({path[i], path[i + 1]});
        }

        return ans;
    }
};
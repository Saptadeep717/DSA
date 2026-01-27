using P = pair<int, int>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, vector<P>> adj;
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        queue<P> q;
        vector<int> result(n + 1, INT_MAX);
        result[src] = 0;
        q.push({src, 0});
        int steps = 0;
        while (!q.empty() && steps <= k) {
            int N = q.size();
            while (N--) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();
                for (auto& it : adj[node]) {
                    int neigh = it.first;
                    int d = it.second;
                    if (dist + d < result[neigh]) {
                        result[neigh] = dist + d;
                        q.push({neigh, dist + d});
                    }
                }
            }
            steps++;
        }
        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};
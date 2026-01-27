using P = pair<int,int>;
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<P>>adj;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];

            adj[u].push_back({v,wt});
            // revrese graph
            adj[v].push_back({u,2*wt});

        }

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<int>result(n+1, INT_MAX);
        result[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node==n-1)return result[n-1];

            for(auto &it : adj[node]){
                int neigh = it.first;
                int dist = it.second;
                if(dist + d < result[neigh]){
                    pq.push({dist+d,neigh});
                    result[neigh] = dist+d;
                }
            }
        }
        return -1;

    }
};
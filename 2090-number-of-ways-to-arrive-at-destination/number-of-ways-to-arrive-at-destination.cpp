class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long,long> , vector<pair<long,long>> , greater<pair<long,long>>>q;
        vector<long long>dist(n,1e18),ways(n,0);
        q.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        int m = 1e9+7;
        
        while(!q.empty()){
            long long distance = q.top().first;
            long long node = q.top().second;
            q.pop();
            
            for(auto it : adj[node]){
                long adjNode = it.first;
                long edW = it.second;
                if(dist[adjNode] > distance + edW){
                    dist[adjNode] = distance + edW;
                    q.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist[adjNode] == distance + edW){
                    ways[adjNode] = (ways[node] + ways[adjNode])%m;
                }
            }
        }
        return ways[n-1]%m;
    }
};
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,char>>>adj;

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back({v,'R'});
            adj[v].push_back({u,'F'});
        }

        queue<int>q;
        vector<bool>vis(n+1,false);
        q.push(0);
        vis[0]=true;
        int ans =0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it : adj[node]){
                if(!vis[it.first]){
                    if(it.second=='R') ans++;
                    q.push(it.first);
                    vis[it.first]=true;
                }
            }
        }
        return ans;
    }
};
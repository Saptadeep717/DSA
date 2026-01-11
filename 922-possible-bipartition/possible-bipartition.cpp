class Solution {
public:

    bool dfs(int node,unordered_map<int,vector<int>>&adj, vector<int>&color, int c){
        color[node]=c;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(!dfs(it,adj,color,!c)) return false;
            }else if(color[it]==color[node]) return false;
        }

        return true;

    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        vector<int>color(n+1,-1);
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(dfs(i,adj,color,0)==false) return false;
            }
           
        }

        return true;
    }
};
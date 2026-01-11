class Solution {
public:
    int dfs(int node, unordered_map<int,vector<int>>&adjL, vector<bool>& hasApple, int parent ){
        int time = 0;
        for(auto &nei : adjL[node]){
            if(nei==parent) continue;
            int timeFromChild = dfs(nei,adjL,hasApple,node);
            if(timeFromChild > 0 || hasApple[nei]){
                time+= timeFromChild + 2;
            }
        }
        return time;
    }


    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adjL;

        for(auto it : edges){
            adjL[it[0]].push_back(it[1]);
            adjL[it[1]].push_back(it[0]);
        }

        int time = dfs(0,adjL,hasApple,-1);
        return time;
    }
};
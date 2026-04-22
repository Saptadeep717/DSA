class Solution {
public:

    vector<int> findTopo(int n ,unordered_map<int,vector<int>>&adjL ) {
        vector<int>indeg(n,0),topo;    
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto it: adjL[i]){
                indeg[it]++;
            }         
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adjL[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        return topo;

        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>>adjL;
        for(int i=0;i<n;i++){
            for(auto &it : graph[i]){
                adjL[it].push_back(i);
            }
        }

        vector<int> ans = findTopo(n,adjL);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
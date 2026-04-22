class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indeg(n,0),topo;
        unordered_map<int,vector<int>>adj;
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
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

            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        return topo.size()==n;

        
    }
};
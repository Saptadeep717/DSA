class DisJointSet{
   
 public:   
     vector<int>parent,size;
    DisJointSet (int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ultP_u = findUPar(u);
        int ultP_v = findUPar(v);
        
        if(ultP_u==ultP_v) return;
        if(size[ultP_u] < size[ultP_v]){
            parent[ultP_u] = ultP_v;
            size[ultP_v] += size[ultP_u];
        }
        
        else{
            parent[ultP_v] = ultP_u;
            size[ultP_u] += size[ultP_v];
        }
    }
    
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxR=0, maxC = 0;
        for(auto it: stones){
            maxR = max(it[0], maxR);
            maxC = max(it[1], maxC);
        }
        
        DisJointSet ds(maxR + maxC + 1);
        //unordered_map<int,int>stoneNodes;
        unordered_set<int> nodes;
        for(auto it: stones){
            int nodeR = it[0];
            int nodeC = it[1] + maxR + 1;
            ds.unionBySize(nodeR, nodeC);
            // stoneNodes[nodeR] = 1;
            // stoneNodes[nodeC] = 1;
            nodes.insert(nodeR);
            nodes.insert(nodeC);
        }
        int cnt=0;
        for(auto it: nodes){
            if(ds.findUPar(it)== it)
                cnt++;
        }
        // for(int i=0; i<(maxR + maxC + 1); i++){
        //      if(ds.parent[i]==i && ds.size[i]>1)
        //         cnt+=1;

        // }
        return n-cnt;
        
    }
};
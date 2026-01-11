class Disjoint{
public:
    vector<int>parent,sizeA;
    Disjoint(int n){
        parent.resize(n);
        sizeA.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUltiParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUltiParent(parent[u]);
    }

    void connect(int u, int v){
        int ulpU = findUltiParent(u);
        int ulpV = findUltiParent(v);

        if(ulpU == ulpV) return;
        if(sizeA[ulpU] < sizeA[ulpV]){
            parent[ulpU] = ulpV;
            sizeA[ulpV] += sizeA[ulpU];
        }
        else{
            parent[ulpV] = ulpU;
            sizeA[ulpU] += sizeA[ulpV];
        }
    }


};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(auto key : rooms[room]){
                if(!vis[key]){
                    vis[key]=1;
                    q.push(key);
                }
            }
        }
        
        for(auto it : vis){
            if(!it) return false;
        }
        return true;
    }
};
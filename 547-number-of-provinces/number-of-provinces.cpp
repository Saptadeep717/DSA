class Disjoint{
public:
    vector<int>parent,size;

    Disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }

    int findUltimateParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void join(int u, int v){
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(pu==pv) return;

        if(size[pu] <= size[pv]){
            size[pv]+=size[pu];
            parent[pu] = pv;
        }else{
            size[pu]+=size[pv];
            parent[pv] = pu;
        }
    }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoint ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    ds.join(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cout<<ds.findUltimateParent(i)<<" ";
            if(ds.findUltimateParent(i)==i) cnt++;
        }
        return cnt;
    }
};
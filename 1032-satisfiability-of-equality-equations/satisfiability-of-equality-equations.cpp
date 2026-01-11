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
    bool equationsPossible(vector<string>& eqns) {
        int n = eqns.size();
        Disjoint ds(26);

        for(int i=0;i<n;i++){
            string e = eqns[i];
            if(e[1]!='!' && e[0]!=e[3]){
              ds.connect(e[0]-'a',e[3]-'a');
            }
        }

        for(int i=0;i<n;i++){
            string e = eqns[i];
            if(e[1]=='!'){
             if (ds.findUltiParent(e[0] - 'a') ==
                    ds.findUltiParent(e[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};
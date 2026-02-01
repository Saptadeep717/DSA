class Disjoint{
    public:
    vector<int>parent,sizeA;
    Disjoint(int n){
        parent.resize(n);
        sizeA.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUltParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUltParent(parent[u]);
    }

    void unionF(int &u, int &v){
        int ulpU = findUltParent(u);
        int ulpV = findUltParent(v);

        if(ulpU == ulpV) return;

        if(sizeA[ulpU] < sizeA[ulpV]){
            parent[ulpU] = ulpV;
            sizeA[ulpV]+= sizeA[ulpU];
        }else{
            parent[ulpV] = ulpU;
            sizeA[ulpU]+= sizeA[ulpV];
        }

    }
};

bool isSimilar(string& a, string& b){
    int n = a.size(), diff=0;
    for(int i=0;i<n;i++){
        if(a[i] != b[i]) diff++;
    }
    return diff==0 || diff==2;
}
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        Disjoint ds(n);
        int grpCnt = n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j]) && ds.findUltParent(i) != ds.findUltParent(j) ){
                    ds.unionF(i,j);
                    grpCnt--;
                }
            }
        }

        return grpCnt;
    }
};
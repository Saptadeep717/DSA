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

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            indegree[e[1]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
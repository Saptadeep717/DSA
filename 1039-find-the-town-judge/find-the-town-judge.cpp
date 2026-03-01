class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int>indeg(n+1),outdeg(n+1);

        for(auto &it : trust){
            indeg[it[1]]++;
            outdeg[it[0]]++;
        }
        for(int i=0;i<=n;i++){
            if(indeg[i]==n-1 && outdeg[i]==0) return i;
        }
        return -1;
    }
};
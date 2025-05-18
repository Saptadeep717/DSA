class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans=0;
        if(rungs[0] > dist) ans= (rungs[0] - 1)/dist;
        int n = rungs.size();
        for(int i=0;i<n-1;i++){
            if(rungs[i+1] - rungs[i] > dist) ans+= (rungs[i+1] - rungs[i] -1)/dist;
        }

        return ans;
    }
};
class Solution {
public:
    bool compare(vector<int>&currBox, vector<int>&prevBox){
        return currBox[0]>=prevBox[0] && currBox[1]>=prevBox[1] && currBox[2]>=prevBox[2]; 
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort dimensions inside every cuboid
        for(auto &it:cuboids){
            sort(it.begin(),it.end());
        }
        // sort all cuboids
        sort(cuboids.begin(), cuboids.end());
        int ans = 0;
        int n = cuboids.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i] = cuboids[i][2];
            for(int prev=0;prev<i;prev++){
                if(compare(cuboids[i], cuboids[prev])){
                     dp[i] = max(dp[i], cuboids[i][2] + dp[prev]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
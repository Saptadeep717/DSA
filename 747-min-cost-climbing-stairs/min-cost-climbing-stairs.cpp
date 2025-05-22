class Solution {
public:

    int solve(int i, vector<int>&v, int n,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int step1 = v[i] + solve(i+1,v,n,dp);

        int step2 = v[i]+solve(i+2,v,n,dp);

        return dp[i]= min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);

        int path1 =solve(0,cost,n,dp);
        int path2 = solve(1,cost,n,dp);

        return min(path1,path2);
    }
};
class Solution {
public:
    int dp[1001];
    int solve(int level, vector<int>&cost,int n){
        //if(level>n) return INT_MAX;
        if(level==n)return 0;
        if(dp[level]!=-1) return dp[level];
        int ans =INT_MAX;
        for(int step=1;step<=2;step++){
            if(step+level<=n){
                ans = min(ans,cost[level]+solve(level+step,cost,n));
            }
        }
        return dp[level] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(0,cost,n),solve(1,cost,n));
    }
};
class Solution {
public:
    int dp[46];
    int solve(int level, int n){
        //pruning

        //base case
        if(level==n) return 1;

        //caching
        if(dp[level]!= -1) return dp[level];
        int ans =0;
        //choices 
        for(int step=1;step<=2;step++){
            //check
            if(level+step <= n){
                // move
                ans+=solve(level+step,n);
            }
        }
        return dp[level] = ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
    }
};
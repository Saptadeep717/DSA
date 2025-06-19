class Solution {
public:
    long long dp[100001][2];
    long long solve(int i, vector<int>&nums,bool isPositive){
        if(i>=nums.size()) return 0;
        if(dp[i][isPositive] != -1) return dp[i][isPositive];

        long long curr = isPositive ? nums[i] : -1 * nums[i];

        return dp[i][isPositive] = max( curr + solve(i+1,nums,!isPositive) , solve(i+1,nums,isPositive));
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,true);
       
    }
};
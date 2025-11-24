class Solution {
public:
    int solve(vector<int>& nums,int i,int k,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(k==0) return 0;
            return 1e9;
        }
        if(k<=0) return 1e9;
        if(dp[i][k] != -1) return dp[i][k];
        int sum=0,ans =1e9;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            ans = min(ans, max(sum,solve(nums,j+1,k-1,dp)));
        }
        return dp[i][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(nums,0,k,dp);
    }
};
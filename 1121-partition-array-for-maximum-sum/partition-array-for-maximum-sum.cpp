class Solution {
public:
int solve(vector<int>& nums,int i,int k,vector<int>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i]!= -1) return dp[i];
        int ans=0,mx=-1e9;
        for(int j=i; j< min((int)nums.size(),i+k);j++){
            mx= max(mx,nums[j]);
            ans =  max(ans, (mx*(j-i+1) + solve(nums,j+1,k,dp)));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,0,k,dp);
    }
};
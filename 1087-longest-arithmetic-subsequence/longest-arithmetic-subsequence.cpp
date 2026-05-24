class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        vector<unordered_map<int,int>>dp(n);
        for(int i=0;i<n;i++){
            for(int prev =0; prev<i;prev++){
                int diff = nums[i] - nums[prev];
                if(dp[prev].count(diff)){
                    dp[i][diff] = dp[prev][diff] + 1;
                }else dp[i][diff]=2;
                
                ans = max(ans,dp[i][diff]);
            }
           
        }
        return ans;
    }
};
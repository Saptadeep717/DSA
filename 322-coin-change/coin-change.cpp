class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));
        
        dp[n][0] = 0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int t=0; t<=amount;t++){
                int notTake = dp[ind+1][t];
                int take = INT_MAX;
                if(coins[ind]<=t){
                    take = 1+dp[ind][t-coins[ind]];
                }
                
                dp[ind][t] = min(take,notTake);
            }
        }
        
        int ans = dp[0][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
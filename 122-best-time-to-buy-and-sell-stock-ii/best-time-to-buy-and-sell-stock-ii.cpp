class Solution {
public:
    
    int solve(int i,bool isBought, vector<int>&prices, vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][isBought] != -1) return dp[i][isBought];
        if(isBought){
            return dp[i][isBought] = max(prices[i]+ solve(i+1,0,prices,dp) , 
                                   0+ solve(i+1,1,prices,dp));
        }
        
        else{
             return dp[i][isBought] = max(-prices[i]+ solve(i+1,1,prices,dp) , 
                                   0+ solve(i+1,0,prices,dp));
        }
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
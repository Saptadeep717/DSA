class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        vector<int>parent(n);
        int lastIndex=0;
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i = 0; i<n; i++ ){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev]< nums[i] && dp[i] < 1+dp[prev]){
                    dp[i] =  1+dp[prev];
                    parent[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex=i;
            }
            
        }
        vector<int>lis;
        lis.push_back(nums[lastIndex]);
        while(parent[lastIndex] != lastIndex){  
            lastIndex = parent[lastIndex];
            lis.push_back(nums[lastIndex]);     
        }
        for(auto it: lis)cout<<it<<" ";

        return maxi;
    
    }
};
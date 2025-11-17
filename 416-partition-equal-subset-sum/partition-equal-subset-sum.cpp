class Solution {
public:
    bool solve(vector<int>& nums, int target, int i, int n,
               vector<vector<int>>& dp) {

        if (i == n) {
            return target == 0;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        bool not_pick = solve(nums, target, i + 1, n,dp);
        bool pick;
        if (nums[i] <= target) {
            pick = solve(nums, target - nums[i], i + 1, n,dp);
        }

        return dp[i][target] = (pick || not_pick);
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(nums, sum, 0, n, dp);
    }
};
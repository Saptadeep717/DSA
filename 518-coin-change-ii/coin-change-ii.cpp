class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned int>> dp(
            n + 1,
            vector<unsigned int>(amount + 1, 0)
        );

        // One way to form amount 0:
        // choose nothing
        for(int i=0;i<=n;i++)dp[i][0]=1;

        for(int ind = n - 1; ind >= 0; ind--) {

            for(int a = 1; a <= amount; a++) {

                unsigned int notTake =
                    dp[ind + 1][a];

                unsigned int take = 0;

                if(coins[ind] <= a) {

                    take = dp[ind][a - coins[ind]];
                }

                dp[ind][a] = take + notTake;
            }
        }

        return (int)dp[0][amount];
    }
};
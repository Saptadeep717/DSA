class Solution {
public:
    int dp[10002];
    int solve(int x, int y) {
        if (x <= y)return y - x;
        if(dp[x]!=-1) return dp[x];
        int res = x - y;
        res = min(res, solve(x / 5, y) + 1 + x % 5);
        res = min( res, 1 + ( 5 - x % 5 ) + solve( ( x + (5 - x % 5) ) / 5, y ));
        res = min(res, solve(x / 11, y) + 1 + x % 11);
        res = min( res, 1 + ( 11 - x % 11) + solve( ( x + (11 - x % 11) ) / 11, y ));
        return dp[x] = res;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        memset(dp, -1, sizeof(dp));
        return solve(x, y);
    }
};
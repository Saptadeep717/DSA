class Solution {
public:
    const int MOD = 1000000007;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        if (n > 1000) {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int left = i + 1;
                    int right = j - 1;
                    while (left <= right && s[left] != s[i]) {
                        left++;
                    }
                    while (left <= right && s[right] != s[i]) {
                        right--;
                    }
                    if (left > right) {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                    } else if (left == right) {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                    } else {
                        dp[i][j] = (2LL * dp[i + 1][j - 1] -
                                    dp[left + 1][right - 1] + MOD) %
                                   MOD;
                    }
                } else {
                    dp[i][j] =
                        ((long)dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) %
                        MOD;
                    if (dp[i][j] < 0) {
                        dp[i][j] += MOD;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
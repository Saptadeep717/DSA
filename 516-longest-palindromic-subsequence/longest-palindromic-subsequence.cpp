class Solution {
public:
    int solve(string& s, string& t, vector<vector<int>>& dp, int i, int j,
              int n) {
        if (i < 0 || j < 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            dp[i][j] = 1 + solve(s, t, dp, i - 1, j - 1, n);
        }
        else dp[i][j] = max(solve(s, t, dp, i - 1, j, n),
                              solve(s, t, dp, i, j - 1, n));
        return dp[i][j];                      
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        vector<vector<int>> dp(n , vector<int>(n , -1));
        vector<vector<int>>tab(n+1 , vector<int>(n+1 , 0));
        reverse(t.begin(), t.end());
        // int ans = solve(s, t, dp, n-1, n-1, n);
        // return ans;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    tab[i][j]=1+tab[i-1][j-1];
                }
                else{
                    tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
                }
            }
        }
        return tab[n][n];
    }
};
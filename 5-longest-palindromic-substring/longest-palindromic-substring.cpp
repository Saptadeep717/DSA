class Solution {
public:
    int dp[1001][1001];
    int rec(int l, int r, string &s){
        if(r-l+1 <=1) return 1;

        if(dp[l][r] != -1) return dp[l][r];
        int ans = (s[l]==s[r]) && rec(l+1, r-1,s);
        return dp[l][r] = ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        int maxi=-1;string temp;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(rec(i,j,s)){
                    if(j-i+1 > maxi){
                        maxi=j-i+1;
                        temp=s.substr(i,maxi);
                    }
                }
            }
        }

        return temp;
    }
};
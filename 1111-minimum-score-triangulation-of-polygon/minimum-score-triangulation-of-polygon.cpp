class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&v, int i, int j){
        // two points can't form triangle
        if(i+1==j)return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans,v[i]*v[j]*v[k] + solve(v,i,k) + solve(v,k,j));
        }
        return dp[i][j] = ans;
        
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return solve(values,0,n-1);
    }
};
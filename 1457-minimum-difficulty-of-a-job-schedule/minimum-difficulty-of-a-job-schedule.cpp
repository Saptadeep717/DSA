class Solution {
public:
    int dp[301][11];
    int solve(vector<int>&job,int n, int d, int idx){
        if(d==1){
            int maxD = job[idx];
            for(int i=idx;i<n;i++){
                maxD= max(maxD,job[i]);
            }
            return maxD;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int maxD= job[idx];
        int finalR = INT_MAX;
        for(int i=idx;i<=n-d;i++){
            maxD = max(maxD,job[i]);
            int result = maxD + solve(job,n,d-1,i+1);
            finalR = min(finalR,result);
        }

        return dp[idx][d] =  finalR;
    }
    int minDifficulty(vector<int>& jobD, int d) {
        int n = jobD.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        int ans = solve(jobD,n,d,0);
        return ans;
    }
};
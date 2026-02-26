class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int mod = 1e9+7;
        int n = nums.size();
        long long sum =0;
        vector<int>pre(n+1,0),cumSum(n,0);

        for(auto &it:requests){
            pre[it[0]]+=1;
            if(it[1]+1 < n){
                pre[it[1]+1] -=1;
            }
        }
        cumSum[0] = pre[0];
        for(int i=1;i<n;i++){
            cumSum[i] = cumSum[i-1]+pre[i];
        }
        sort(cumSum.rbegin(),cumSum.rend());
        sort(nums.rbegin(),nums.rend());

        for(auto it:nums) cout<<it<<" ";
        cout<<endl;
        for(auto it:cumSum) cout<<it<<" ";
        for(int i=0;i<n;i++){
            if(cumSum[i]>0){
                sum = (sum + (1LL * cumSum[i] * nums[i]) % mod) % mod;
            }
        }
        return (int)sum;
    }
};
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> v(k, LLONG_MAX);
        long long prefixSum = 0, ans = LLONG_MIN;
        v[0] = 0; // prefix before the first element
            for (int i = 1; i <= n; i++) {
            prefixSum += nums[i - 1];
            int rem = i % k;
            if (v[rem] != LLONG_MAX) {
                // this is possible ans
                ans = max(ans, prefixSum - v[rem]);
            }
            v[rem] = min(v[rem], prefixSum);
        }
        return ans;
    }
};
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            st.reserve(n);

            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                st.insert(nums[j]);
                if (st.count(sum)) {
                    cnt++;
                }
            }
        }
        return cnt;
        
        
    }
};
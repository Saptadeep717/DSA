class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size(),j=0,res=0;
        for (int i = 0; i < n; i = max(i + 1, j - 1))
            for (j = i + 1; j < n && nums[j] == nums[i] + (j - i) % 2; ++j)
                res = max(res, j - i + 1);
        return res > 1 ? res : -1;
    }
};
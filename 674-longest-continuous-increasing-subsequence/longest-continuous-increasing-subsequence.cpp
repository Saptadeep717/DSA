class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 0, j = 1, val = nums[0];
        int n = nums.size();
        int cnt = 0, maxi = -1e9;

        while (j < n) {
            if (nums[j] <= val) {
                maxi = max(maxi, j-i);
                i=j;
                
            }
            val = nums[j];
            j++;
        }
        maxi = max(maxi, j-i);
        return maxi;
    }
};
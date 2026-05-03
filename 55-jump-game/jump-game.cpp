class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachedIdx = nums[0];
        for(int i=1;i<n;i++){
            if( i > maxReachedIdx) return false;
            maxReachedIdx = max(maxReachedIdx,i+nums[i]);
         
        }
        return true;
    }
};
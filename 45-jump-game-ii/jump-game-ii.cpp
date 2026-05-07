class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;

        int maxReachPossible = 0;

        int currentJumpBoundary = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            maxReachPossible = max(maxReachPossible, i + nums[i]);

            // If current jump can directly reach end
            if(maxReachPossible >= nums.size() - 1) {
                return jumps + 1;
            }

            // current range exhausted
            if(i == currentJumpBoundary) {

                jumps++;

                currentJumpBoundary = maxReachPossible;
            }
        }

        return jumps;
    }
};
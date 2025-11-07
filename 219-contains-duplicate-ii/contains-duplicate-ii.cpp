class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> last; 
        for (int j = 0; j < (int)nums.size(); ++j) {
            int x = nums[j];
            if (last.count(x) && j - last[x] <= k) return true;
            last[x] = j; 
        }
        return false;
    }
};
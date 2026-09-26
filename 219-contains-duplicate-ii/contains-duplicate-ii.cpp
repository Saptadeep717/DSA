class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mpp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto it:mpp){
            vector<int>v=it.second;
            for(int i=0;i<v.size()-1;i++){
                if(v[i+1]-v[i] <= k) return true;
            }
        }
        return false;
    }
};
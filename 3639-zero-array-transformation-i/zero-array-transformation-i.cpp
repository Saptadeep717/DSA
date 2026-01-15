class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n,0);

        for(auto &q : queries){
            int L = q[0], R = q[1];
            diff[L]+=1;
            if(R+1 < n) diff[R+1]-=1;
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<n;i++){
            if(nums[i] > diff[i]) return false;
        }
        return true;

    }
};
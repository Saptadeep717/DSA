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
        //creating cummalitive sum array to check in one index at max how many operation we can do
        for(int i=0;i<n;i++){
            diff[i]+= i==0 ? 0 : diff[i-1];
            if(nums[i] > diff[i]) return false;
        }
        // if # of operation is smaller than the value then that value can't be reduced to 0, hence zeroArray transformation is not possible
        return true;

    }
};
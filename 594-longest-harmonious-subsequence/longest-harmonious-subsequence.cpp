class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans=-1,val=0;
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){
            if(mpp.count(it.first+1)){
                val = mpp[it.first] + mpp[it.first+1];
            }

            ans = max(ans,val);

        }

        return ans;

       
    }
};
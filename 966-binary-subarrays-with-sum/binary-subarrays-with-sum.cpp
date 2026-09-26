class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size(),sum=0,ans=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int j=0;j<n;j++){
            sum+=nums[j];

            if(mpp.count(sum-k))ans+=mpp[sum-k];
            mpp[sum]+=1;
        }
        return ans;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,mxSum=INT_MIN;
        for(auto it:nums){
            sum+=it;
            mxSum=max(sum,mxSum);
            if(sum<0) sum=0;
        }

        return mxSum;
    }
};
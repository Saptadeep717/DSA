class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int maxi = INT_MIN, mini =0,n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi = max(maxi,sum);
            if(sum<0) sum=0;
        }
        if(maxi <0) return maxi;
         for(int i=0;i<n;i++){
            sum+=nums[i];
            mini = min(mini,sum);
            if(sum>0) sum=0;
        }

        return max(total-mini, maxi);
    }
};
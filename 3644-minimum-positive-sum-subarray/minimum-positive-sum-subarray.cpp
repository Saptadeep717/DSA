class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int i=0,j=0,sum=0,ans=INT_MAX;
        for(int j = l;j<=r;j++){
            int sum=0;
            for(int i=0;i<j;i++){
                sum+=nums[i];
            }
            if(sum>0) ans=min(ans,sum);

            for(int i=j;i<n;i++){
                sum+=nums[i];
                sum-=nums[i-j];
                if(sum>0) ans=min(ans,sum);
            }
             

        }
        return ans!=INT_MAX ? ans : -1;
    }
};
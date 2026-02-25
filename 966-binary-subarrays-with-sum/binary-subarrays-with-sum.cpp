class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int sum = 0, cnt =0;
        int i=0,j=0, n=nums.size();
        int cntZero=0;
        while(j<n){
            sum+=nums[j];
            
            while(i<j && (nums[i]==0 || sum>k )){
                if(nums[i]==0){
                    cntZero++;
                }else cntZero=0;
                sum-=nums[i];
                i++;
            }
            if(sum==k)cnt += 1+cntZero;
            j++;
        }
        return cnt;    
    }
};
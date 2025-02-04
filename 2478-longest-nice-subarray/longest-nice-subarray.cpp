class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int j=0,ans=0,mask=0;
        for(int i=0;i<n;i++){
            while((nums[i] & mask) !=0){
                mask^=nums[j++];

            }
            mask |= nums[i];
            ans=max(ans,i-j+1);
        }

        return ans;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size(),zc=0, i=0,maxi=0;

       for(int j=0;j<n;j++){
            if(nums[j]==0)zc++;

            while(zc>k){
                if(nums[i]==0)zc--;
                i++;
            }
            maxi = max(maxi,j-i+1);
       }
       return maxi;
    }
};
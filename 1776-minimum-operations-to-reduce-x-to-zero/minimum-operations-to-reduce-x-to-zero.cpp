class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum= accumulate(nums.begin(),nums.end(),0);

        int n = nums.size();
        int currSum=0,maxLength=-1;
        int i=0,j=0;
        while(j<n){
            currSum+=nums[j];

            while(i<=j && currSum > sum-x) currSum-=nums[i++];

            if(currSum == sum-x) maxLength = max(maxLength,j-i+1);
            j++;
        }

        return maxLength==-1 ? -1 : n-maxLength;
        
    }
};
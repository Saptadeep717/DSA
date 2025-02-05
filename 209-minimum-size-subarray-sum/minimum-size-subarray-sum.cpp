class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(),nums.end(),0) < target) return 0;
        int n = nums.size();
        int preSum =0,size =INT_MAX;
//         for(int i=0,j=0; i<n;i++){
//             preSum += nums[i];
            
//             if(preSum >= target){
//                 size = min(i-j+1,size);
                
//                 while(preSum >= target){
//                     preSum -= nums[j];
//                     size = min(size, i-j+1);
//                     j++;
//                 }
                
//             }
            
            
//         }
//         return size;
        
        int i=0,j=0;
        while(j<n){
            preSum+=nums[j];
            if(preSum>=target){
                size = min(j-i+1,size);
                while(preSum >= target){
                    preSum -= nums[i];
                    size = min(size, j-i+1);
                    i++;
                }
                
            }
            j++;
        }
        return size;
        
    }
};
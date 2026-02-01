class Solution {
public:
    int minimumCost(vector<int>& nums) {
       int lowest = 51, secondLowest = 51;

       for(int i=1;i<nums.size();i++){
            if(nums[i] < secondLowest){
                secondLowest = nums[i];
            }
            if(lowest > secondLowest)swap(lowest, secondLowest);

       }

       return nums[0]+lowest+secondLowest;
        
    }
};
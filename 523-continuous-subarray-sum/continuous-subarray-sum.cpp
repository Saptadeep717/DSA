class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod=0;
        map<int,int>modSeen;
        modSeen[0]=-1;

        for(int i=0;i<n;i++){
            prefixMod = (prefixMod + nums[i]) %k;
            if (modSeen.find(prefixMod) != modSeen.end()) {
                if(i-modSeen[prefixMod] > 1)return 1;
            }else{
                modSeen[prefixMod]=i;
            }
        }
        return 0;
        
    }
};
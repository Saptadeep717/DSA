class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int prod,res=0;
        for(int i=0; i<nums.size(); i++){
            for(int j =i+1; j<nums.size(); j++){
                prod = nums[i]*nums[j];
                mpp[prod]++;
            }
        }
        
        for(auto it:mpp){
            int a = it.second;
            if(a>=2)res+= (a*(a-1))/2;
            
        }
        return res*8;
    }
};
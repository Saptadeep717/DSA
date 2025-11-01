class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
        vector<int>v,ans(n,0);
        int mul=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)mul*=nums[i];
            else{
                if(v.size()<=2)v.push_back(i);
            } 
        }
       if(v.size()){
        if(v.size()==1){
            ans[v[0]]=mul;
        }else return ans;
       }else{
        for(int i=0;i<n;i++){
                ans[i]= mul/nums[i];
            }
       }
       
        return ans;
    }
};
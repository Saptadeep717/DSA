class Solution {
public:
    void solve(vector<int>&nums,int i,int n,vector<int>&temp,vector<vector<int>>&ans){
       
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,i+1,n,temp,ans);
        temp.pop_back();
        solve(nums,i+1,n,temp,ans);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,nums.size(),temp,ans);
        return ans;
    }
};
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans=0, i=0,j=0;
        //vector<long long>v(1e9+1,0);
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            //int sz = *max_element(v.begin(),v.end());
            // int maxi = -1e9;
            // for(auto it:mpp){
            //     maxi = max(maxi,it.second);
            // }
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            
            j++;
        }
        return ans;
    }
};
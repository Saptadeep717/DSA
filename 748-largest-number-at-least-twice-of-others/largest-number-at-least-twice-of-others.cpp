class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int,int>>v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());
        int ans=-1;
        if(2*v[n-2].first > v[n-1].first){
            ans=-1;
        }else ans=v[n-1].second;

        return ans;
    }
    
};
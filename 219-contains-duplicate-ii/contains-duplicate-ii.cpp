class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }


        for(auto it : mpp){
            if((it.second).size() > 1 ){
                int diff = it.second[1] - it.second[0];
                cout<<diff<<endl;
                for(int i=1;i<it.second.size()-1;i++){
                    diff = min(diff, it.second[i+1]-it.second[i]);
                    cout<<diff<<endl;
                    if(diff<=k) return true;
                }
                if(it.second[1] - it.second[0]<=k) return true;
            }
        }
        return false;
    }
};
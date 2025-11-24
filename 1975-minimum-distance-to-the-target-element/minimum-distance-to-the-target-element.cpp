class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());
        if(temp[0].first==temp[n-1].first) return 0;

        for(int i=0;i<n;i++){
            cout<<temp[i].first <<"->"<<temp[i].second<<" ";
        }cout<<endl;
        int mini = 1e9;
        for(int i=0;i<n;i++){
            if(temp[i].first==target){
                mini = min(mini,abs(temp[i].second - start));
                
            }
        }
        return mini;

       
    }
};
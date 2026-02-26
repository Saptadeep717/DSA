class Solution {
public:
    using ll = long long;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,ll>mpp;
        vector<vector<ll>>ans;
        for(auto &it: segments){
            mpp[it[0]]+=it[2];
            mpp[it[1]]-=it[2];
        }
        auto it = mpp.begin();
        ll sum = it->second;
        int start = it->first;
        it++;

        while(it!=mpp.end()){
            if(sum>0){
                ans.push_back({start,it->first,sum});
            }
            start=it->first;
            sum+=it->second;
            it++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n);
        unordered_map<int,int>mpp;
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                ans[i]=1;
                s.insert(i);
            }

            else {
                if(mpp.count(rains[i])){
                    auto it = s.lower_bound(mpp[rains[i]]);
                    if(it==s.end())return {};
                    int idx = *it;
                    ans[idx]=rains[i];
                    s.erase(idx);
                }
                

                mpp[rains[i]]=i;
                ans[i]=-1;
               


            }
        }

      
        return ans;
    }
};
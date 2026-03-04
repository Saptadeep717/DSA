class Solution {
public:
    using p = pair<int,int>;
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<p>v;
        int n = plantTime.size();
        for(int i=0;i<n;i++){
            v.push_back({plantTime[i],growTime[i]});
        }
        // sort with growTime descending
        sort(v.begin(),v.end(), [&](p a, p b){
            return a.second>b.second;
        });

        int maxBloomDays =0;
        int prevPlantDays =0;
        for(int i=0;i<n;i++){
            prevPlantDays += v[i].first;
            int totalDaysToBloomASeed = prevPlantDays+v[i].second;
            maxBloomDays = max(maxBloomDays,totalDaysToBloomASeed);
        }
        return maxBloomDays;
    }
};
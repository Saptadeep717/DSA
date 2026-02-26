class Solution {
public:
    using p = pair<int,int>;
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<p>events;
        for(auto &it:logs){
            events.push_back({it[0],+1});
            events.push_back({it[1],-1});
        }

        sort(events.begin(),events.end());
        int year = 2050, maxPop=0,currPop;
        for(auto &it:events){
            currPop+=it.second;
            if(currPop>maxPop){
                maxPop = currPop;
                year = it.first;
            }
        }
        return year;
    }
};
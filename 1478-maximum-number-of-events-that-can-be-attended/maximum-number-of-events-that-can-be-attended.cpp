class Solution {
    
public:
    
    static bool cmp (vector<int> &a, vector<int> &b)
       {
            if(a[1]<b[1]) return true;
            else if(a[1]==b[1]) return a[0]<b[0];
            return false;
       }
    
    int maxEvents(vector<vector<int>>& events) {
       
        
        
        int cnt=0;
        sort(events.begin(), events.end(),cmp);
        int n = events[events.size()-1][1];
        set<int>days;
        for(int i=1; i<=n; i++) days.insert(i);
        
        for(auto it : events){
            int start = it[0], end = it[1];
            auto closeDay = days.lower_bound(start);
            
            if(closeDay==days.end() || *closeDay > end) continue;
            else{
                cnt++;
                days.erase(closeDay);
            }
        }
        return cnt;
    }
};
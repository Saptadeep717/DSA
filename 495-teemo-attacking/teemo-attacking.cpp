class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int cnt=duration;
        for (int i = 1; i < n; i++) {
           int gap = timeSeries[i] - timeSeries[i-1];
            cnt+= min(gap,duration);
        }
        return cnt;
    }
};
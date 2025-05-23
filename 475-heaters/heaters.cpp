class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());

        int ans = 0;
        for (int i = 0; i < houses.size(); i++) {
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int dist1 = (it==heaters.end()) ? INT_MAX : abs(*it-houses[i]);
            int dist2 = (it == heaters.begin()) ? INT_MAX : abs(*prev(it) - houses[i]);
           ans = max(ans, min(dist1,dist2));
        }

        return ans;

        
    }
};
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size();
        int i=0;
        if(costs[0]>coins) return 0;
        int cnt=0;
        while(i<n){
            if(costs[i]>coins) break;
            coins-=costs[i];
            cnt++;
            i++;
        }
        return cnt;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int,int>>v;
        int n=sp.size();

        for(int i=0;i<n;i++){
            v.push_back({pos[i],sp[i]});
        }
        sort(v.rbegin(),v.rend());
        int ans=1;
        double prevTime = (double) (target - v[0].first)/v[0].second;

        for(int i=1;i<n;i++){
            double currTime =(double) (target - v[i].first)/v[i].second;

            if(currTime > prevTime){
                ans++;
                prevTime = currTime;
            }
        }
        return ans;
    }
};
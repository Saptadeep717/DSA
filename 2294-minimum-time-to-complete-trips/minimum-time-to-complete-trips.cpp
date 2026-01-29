using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>&time, int &trips, ll &mid){
        ll cnt =0;
        for(int i=0;i<time.size();i++){
            cnt+= mid/time[i];
        }
        return cnt>=trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        ll s = 1;
        ll e = 1LL * time[n-1]*totalTrips;
        ll ans;
        while(s<=e){
            ll mid = s + (e-s)/2;

            if(isPossible(time,totalTrips,mid)){
                ans = mid;
                e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
};
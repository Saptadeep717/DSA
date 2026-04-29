
using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& candies, long long k, int mid, int n){
        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt+= (candies[i]/mid);
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        ll sum = accumulate(candies.begin(),candies.end(),0LL);
        if(sum < k) return 0;
        int ans =0;
        int low =1;
        int high = *max_element(candies.begin(),candies.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(candies,k,mid,n)){
                ans = mid;
                low=mid+1;        
            }else high=mid-1;
        }
        return ans;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int eatingSpeed, int n){
        long long totalTime = 0;
        for(int i=0;i<n;i++){
            totalTime+= ceil((double)piles[i]/(double)eatingSpeed);
        }
        return totalTime<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans =-1;
        if(h<n) return ans;
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(piles,h,mid,n)){
                ans = mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};
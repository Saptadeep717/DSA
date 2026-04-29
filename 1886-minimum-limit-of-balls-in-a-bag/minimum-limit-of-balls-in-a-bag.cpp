class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int maxNoBallsInBag, int n){
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt += (nums[i]-1)/maxNoBallsInBag;
        }
        return cnt<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans =high;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(nums,maxOperations,mid,n)){
                ans = mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};
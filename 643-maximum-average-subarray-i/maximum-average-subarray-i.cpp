class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0, n=nums.size();
        double ans=-1e9,sum=0;
        //if(k==1 && n==1) return nums[0];
        while(j<n){
            sum+=nums[j];
            if(j-i+1 > k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
                ans = max(ans,sum/(double)k);
            }
            j++;
        }
        return ans;
    }
};
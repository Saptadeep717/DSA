class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int weight, int n){
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]<=weight){
                sum+=weights[i];
            }else{
                cnt++;
                sum=weights[i];
            }
        }    
        cnt+=1;
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans =1;
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        cout<<low<<" "<<high<<endl;
        while(low<=high){
            int mid = low + (high-low)/2;
            cout<<mid<<" ";
            if(isPossible(weights,days,mid,n)){
                ans = mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};
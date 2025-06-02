class Solution {
public:
    bool possible(vector<int>&v,double h, int mid){
        int n = v.size();
        double val=0;
        for(int i=0;i<n-1;i++){
            val += ceil((double)v[i]/(double)mid);

        }
        val+=(double)v[n-1]/(double)mid;

        return val<=h;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=0,e=INT_MAX-1;
        //cout<<e;
        int ans=-1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(possible(dist,hour,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
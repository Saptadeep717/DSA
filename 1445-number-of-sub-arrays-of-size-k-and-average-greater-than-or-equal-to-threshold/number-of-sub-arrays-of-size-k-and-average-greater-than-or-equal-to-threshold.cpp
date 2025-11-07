class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0,n=arr.size(),cnt=0,sum=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1==k){
                if(sum/k >= threshold) cnt++;
            }
            else if(j-i+1 > k){
                while(j-i+1 > k){
                    sum-=arr[i];
                    i++;
                }
                if(sum/k >= threshold) cnt++;
            }
            j++;
        }
        return cnt;
    }
};
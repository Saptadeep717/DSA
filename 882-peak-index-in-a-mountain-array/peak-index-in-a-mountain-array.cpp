class Solution {
public:
    
    int peak(vector<int>&arr,int n){
        int s=1, e= n-2;
        while(s<=e){

            int mid = s+(e-s)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]<arr[mid+1]) s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n==1 || arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        return peak(arr,n);
    }
};
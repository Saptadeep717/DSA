class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        int i=0,j=n-1;
        while(i<n){
            if(arr[i] != temp[i]) break;
            i++;
        }
        if(i>=n-1) return 0;
        while(j>=0){
            if(arr[j] != temp[j]) break;
            j--;
        }
        return j-i+1;
    }
};
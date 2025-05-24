class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // int n = arr.size();
        // if(n<3) return false;
        // if(arr[0]>arr[1]) return false;
        // int ind=-1,ind2=-1;
        // for(int i =0;i<n-1;i++){
        //     if(arr[i+1] <= arr[i]){
        //         ind=i;
        //         break;
        //     }

        // }
        // if(ind==-1) return false;
        // for(int i=ind;i<n-1;i++){
        //     if(arr[i+1] >= arr[i]){
        //         ind2=i;
        //         break;
        //     }
        // }

        // if(ind2!=-1) return false;
        // return true;

        int n = arr.size(), i = 0, j = n - 1;
        while (i + 1 < n && arr[i] < arr[i + 1]) i++;
        while (j > 0 && arr[j - 1] > arr[j]) j--;
        return i > 0 && i == j && j < n - 1;
    }
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int n = arr.size(), mini = INT_MAX;
        vector<int>diff;

        for(int i=1;i<n;i++){
            mini = min(mini,abs(arr[i]-arr[i-1]));
            diff.push_back(abs(arr[i]-arr[i-1]));
        }

        for(int i=0;i<diff.size();i++){
            if(diff[i]==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;
    }
};
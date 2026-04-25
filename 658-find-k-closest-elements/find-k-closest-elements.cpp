class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        if (lb == n) 
            return vector<int>(arr.begin() + n - k, arr.end());

        vector<int> ans;

        int i = lb - 1, j = lb;

        while (k--) {
            if (i >= 0 && j < n) {
                if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                    ans.push_back(arr[i--]);
                } else {
                    ans.push_back(arr[j++]);
                }
            } 
            else if (i >= 0) {
                ans.push_back(arr[i--]);
            } 
            else {
                ans.push_back(arr[j++]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
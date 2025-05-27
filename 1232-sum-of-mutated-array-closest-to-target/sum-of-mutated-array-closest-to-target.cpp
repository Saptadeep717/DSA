class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<long long>preSum(n);
        preSum[0]=arr[0];

        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1]+arr[i];
        }

 int left = 0, right = arr[n - 1];
    int bestVal = 0;
    int minDiff = INT_MAX;

    while (left <= right) {
        int mid = (left + right) / 2;

        auto it = upper_bound(arr.begin(), arr.end(), mid);
        int idx = it - arr.begin();

        int currSum = (idx > 0 ? preSum[idx - 1] : 0) + (n - idx) * mid;

        int diff = abs(currSum - target);

        if (diff < minDiff || (diff == minDiff && mid < bestVal)) {
            bestVal = mid;
            minDiff = diff;
        }

        if (currSum < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bestVal;
    }
};
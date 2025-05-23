class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tSum = accumulate(arr.begin(), arr.end(), 0);
        if (tSum % 3 != 0)
            return false;
        int pSum = tSum / 3;

        int currentSum = 0, count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            currentSum += arr[i];
            if (currentSum == pSum) {
                count++;
                currentSum = 0; // reset for next part
            }
        }

        // We need at least 3 such parts
        return count >= 3;
    }
};
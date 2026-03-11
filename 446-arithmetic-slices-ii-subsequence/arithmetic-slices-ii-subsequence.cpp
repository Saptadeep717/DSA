class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        // dp[i] stores a map where:
        // - key: common difference
        // - value: count of arithmetic subsequences ending at index i with that difference
        unordered_map<long, int> dp[n];
        
        int totalCount = 0;
      
        // Iterate through each element as the potential end of an arithmetic subsequence
        for (int i = 0; i < n; ++i) {
            // Check all previous elements as potential second-to-last elements
            for (int j = 0; j < i; ++j) {
                // Calculate the common difference between current and previous element
                // Use long long to prevent integer overflow
                long long diff = static_cast<long long>(nums[i]) - nums[j];
              
                // Get count of arithmetic subsequences ending at j with difference 'diff'
                // This represents subsequences of length >= 2
                int subsequenceCount = dp[j][diff];
              
                // Add to total count (these form valid arithmetic subsequences of length >= 3)
                totalCount += subsequenceCount;
              
                // Update dp[i][diff]:
                // - Add subsequenceCount: extend existing subsequences from j to i
                // - Add 1: create new subsequence of length 2 (nums[j], nums[i])
                dp[i][diff] += subsequenceCount + 1;
            }
        }
      
        return totalCount;
    }
};
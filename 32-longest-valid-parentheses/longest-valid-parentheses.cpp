class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0, maxi = 0;

        // -------------------------------
        // PASS 1: Left → Right
        // Goal:
        //   - Ensure prefix never becomes invalid (no extra ')')
        //   - i.e., close should never exceed open
        // -------------------------------
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open++;
            else close++;

            // If counts match → valid substring found
            // length = total chars = 2 * number of pairs
            if(open == close) {
                maxi = max(maxi, 2 * close);
            }

            // If close > open → prefix invalid (too many ')')
            // This segment can never form a valid substring
            // Reset counters → start fresh from next index
            if(close > open) {
                open = close = 0;
            }
        }

        // Reset for reverse pass
        open = close = 0;

        // -------------------------------
        // PASS 2: Right → Left
        // Goal:
        //   - Handle extra '(' cases missed in forward pass
        //   - Ensure suffix never becomes invalid (no extra '(')
        // -------------------------------
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') open++;
            else close++;

            // If balanced → valid substring
            if(open == close) {
                maxi = max(maxi, 2 * open);
            }

            // If open > close → invalid from this direction
            // Too many '(' → cannot be balanced
            // Reset counters
            if(open > close) {
                open = close = 0;
            }
        }

        return maxi;
    }
};
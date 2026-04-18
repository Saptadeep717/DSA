class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;

        for(int i = 0; i < n; i++){
            set<char> st;

            for(int j = i; j < n; j++){
                if(st.count(s[j])) {
                    break;
                }
                st.insert(s[j]);
                maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};
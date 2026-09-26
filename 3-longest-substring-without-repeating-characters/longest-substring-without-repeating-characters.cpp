class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int n = s.size();
        int ans =0;
        int i=0,j=0;
        while(j<n){
            mpp[s[j]]++;

            while(j-i+1 > mpp.size()){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
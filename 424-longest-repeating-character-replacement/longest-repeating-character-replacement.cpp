class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, n=s.size(), maxFreqInWindow=0,ans=0;
        vector<int>freq(26,0);

        for(int j=0;j<n;j++){
            freq[s[j]-'A']++;
            maxFreqInWindow = *max_element(freq.begin(),freq.end());
            while(j-i+1 - maxFreqInWindow > k){
                freq[s[i]-'A']--;
                i++;
                //maxFreqInWindow = *max_element(freq.begin(),freq.end());
            }

            ans = max(ans, j-i+1);
        }
        return ans;
        
    }
};
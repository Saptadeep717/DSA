class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        for(auto it : s)freq[it-'a']++;
        int maxCnt =0; char ch;
        for(int i=0;i<26;i++){
            if(freq[i] > maxCnt){
                maxCnt = freq[i];
                ch = i+'a';
            }
        }
        if(maxCnt > (n+1)/2) return "";
        string ans = s;
        int i=0;
        while(freq[ch-'a'] > 0){
            ans[i] = ch;
            freq[ch-'a']--;
            i+=2;
        }

        for(char c ='a';c<='z';c++){
            while(freq[c-'a'] > 0){
                if(i>=n) i=1;
                ans[i] = c;
                freq[c-'a']--;
                i+=2;
            }
        }
        return ans;
    }
};
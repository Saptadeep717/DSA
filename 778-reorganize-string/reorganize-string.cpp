class Solution {
public:
    string reorganizeString(string s) {
        vector<int>count(26,0);
        int n = s.size();
        char maxChar; int maxFreq = 0;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a'] > maxFreq){
                maxFreq = count[s[i]-'a'];
                maxChar = s[i];
            }
            

            if(count[s[i]-'a'] > (n+1)/2)return "";
        }

        int i =0;
        string ans = s;
        while(count[maxChar-'a'] > 0){
            ans[i] = maxChar;
            i+=2;
            count[maxChar-'a']--;
        }
        for(char ch = 'a'; ch<='z';ch++){
            while(count[ch-'a'] > 0){
                if(i>=n)i=1;
                ans[i]=ch;
                i+=2;
                count[ch-'a']--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long long>suff(n);
        suff[n-1] = shifts[n-1];

        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1] + shifts[i];
        }
        //string ans="";
        for(auto it : suff) cout<<it<<" ";
       for(int i = 0; i < n; i++) {
            int shift = suff[i] % 26;
            s[i] = char((s[i] - 'a' + shift) % 26 + 'a');
        }
        return s;
    }
};
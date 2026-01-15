class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>v(n,0);
        for(auto &it : shifts){
            int L = it[0];
            int R = it[1];
            int X = it[2];

            if(X==0) X=-1;
            else X=1;

            v[L] += X;
            if(R+1 <n) v[R+1]-=X;

        }
        for(int i=1;i<n;i++){
            v[i] = v[i]+v[i-1];
        }
        
        for(int i =0;i<s.size();i++){
            int sh = v[i]%26;
            if(sh<0) sh+=26;
            s[i] =  char((s[i]-'a' + sh)%26 + 'a');
        }
        return s;
    }
};
class Solution {
    int solve(int index,string s,unordered_set<string>&st,vector<int>&dp){
        if(index == s.size()) return 1;
        if(dp[index]!= -1) return dp[index];
        string temp;
        for(int i=index; i<s.size();i++){
            temp+=s[i];
            if(st.find(temp) != st.end()){
                if(solve(i+1,s,st,dp)) return dp[index] = 1;
                
            }
        }
        return dp[index] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<int>dp(s.size()+1,-1);
        for(auto a : wordDict){
            st.insert(a);
        }
        return solve(0,s,st,dp);
    }
};
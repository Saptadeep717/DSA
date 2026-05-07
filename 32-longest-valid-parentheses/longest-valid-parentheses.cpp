class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), open=0,close=0, maxi =0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else close++;
            if(open == close) maxi = max(maxi,2*close);
            if(close > open) close=open=0;
        }
        open = close = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open == close) maxi = max(maxi,2*open);
            if(close < open) close=open=0;
        }
        return maxi;
    }
};
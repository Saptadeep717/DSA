class Solution {
public:
    void solve(int n, vector<string>&ans, string temp,int i,int op, int cl){
        if(i==2*n){
            ans.push_back(temp);
            return;
        }

        //opening
        if(op<n) solve(n,ans,temp+'(',i+1,op+1,cl);
    
        //closing
        if(cl<op) solve(n,ans,temp+')',i+1,op,cl+1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,ans,"",0,0,0);
        return ans;
    }
};
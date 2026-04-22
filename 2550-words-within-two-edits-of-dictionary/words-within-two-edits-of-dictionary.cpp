class Solution {
public:
    bool isPossible(string &s, string &t){
       int cnt=0;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i])cnt++;
            if(cnt > 2) return false;
        }
        return cnt<=2;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        int n = q.size();
        unordered_set<string>st;
        for(auto it:d)st.insert(it);
        vector<string>ans;
        for(int i=0;i<n;i++){
            string temp = q[i];
            if(st.count(temp)){
                ans.push_back(temp);
                continue;
            }
            for(auto it:st){
                //cout<<it<<" "<<temp<<endl;
                if(isPossible(it,temp)){
                    ans.push_back(temp);
                    break;
                }
            }

        }
        return ans;
    }
};
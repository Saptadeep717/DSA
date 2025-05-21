class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int>st;

        for(auto i:s)st.insert(i);
        int cnt=0;
        for(int i=0;i<g.size();i++){
            auto it = st.lower_bound(g[i]);
            if(*it >= g[i] && it != st.end()){
                cnt++;
                st.erase(it);
            }

        }
        return cnt;
    }
};
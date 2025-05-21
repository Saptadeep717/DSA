class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        multiset<int>st;

        for(auto i:trainers)st.insert(i);
        int cnt=0;
        for(int i=0;i<players.size();i++){
            auto it = st.lower_bound(players[i]);
            if(*it >= players[i] && it != st.end()){
                cnt++;
                st.erase(it);
            }

        }
        return cnt;
    }
};
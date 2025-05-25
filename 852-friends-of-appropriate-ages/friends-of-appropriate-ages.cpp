class Solution {
public:
    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
    int numFriendRequests(vector<int>& ages) {
        //  sort(ages.begin(), ages.end());
        // int cnt=0;
        // for(auto age : ages){
        //     int i=upper_bound(ages.begin(),ages.end(),age)-ages.begin();

        //      int j=upper_bound(ages.begin(),ages.end(),age*0.5 + 7)-ages.begin();

        //      cnt+=max(0,i-j-1);
        // }
    //return cnt;
        unordered_map<int, int> count;
        for (int &age : ages)
            count[age]++;
        int res = 0;
        for (auto &a : count)
            for (auto &b : count)
                if (request(a.first, b.first))
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
        return res;

        
    }
};
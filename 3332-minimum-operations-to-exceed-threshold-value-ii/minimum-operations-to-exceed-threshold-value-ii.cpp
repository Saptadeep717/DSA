class Solution {
public:
    using ll = long long;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(auto &it : nums)pq.push(it);
        int cnt=0;
        while(pq.size()>=2 && pq.top()<k){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            pq.push(2*a + b);
            cnt++;
        }
        return cnt;
    }
};
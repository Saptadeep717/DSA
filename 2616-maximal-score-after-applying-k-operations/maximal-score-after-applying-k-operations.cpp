class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(auto it:nums)pq.push(it);
        long long ans =0;
        while(k--){
            int val = pq.top();
            pq.pop();
            ans+=val;
            if(val%3==0)pq.push(val/3);
            else pq.push((val/3)+1);
        }

        return ans;
    }
};
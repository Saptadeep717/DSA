class Solution {
public:
    using ll =long long;
    using P = pair<int,int>;
    long long findScore(vector<int>& nums) {
        ll ans = 0;
        set<int>visited;
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
            auto entry = pq.top();
            pq.pop();
            int val = entry.first, idx=entry.second;
            if(!visited.count(idx)){
                ans+=val;
                visited.insert(idx);
                if(idx+1<nums.size())visited.insert(idx+1);
                if(idx-1>=0)visited.insert(idx-1);
            }
        }

       

        return ans;

    }
};
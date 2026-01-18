class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        long long ans = 0;
        int n = costs.size();
        int i=0,j=n-1;
        int hired = 0;
        while(hired < k){
            while(pq1.size() < candidates && i<=j){
                pq1.push(costs[i]);
                i++;
            }

            while(pq2.size() < candidates && i<=j){
                pq2.push(costs[j]);
                j--;
            }

            long long mini1 = pq1.size()>0 ? pq1.top() : LLONG_MAX, mini2 = pq2.size()>0 ? pq2.top() : LLONG_MAX;

            if(mini1<=mini2){
                ans+= mini1;
                pq1.pop();
            }else{
                ans+=mini2;
                pq2.pop();
            }
            hired++;
        }

        return ans;
    }
};
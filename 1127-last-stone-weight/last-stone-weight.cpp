class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxH;

        for(auto it : stones) maxH.push(it);

        while(maxH.size()>1){
            int a = maxH.top();
            maxH.pop();
            int b = maxH.top();
            maxH.pop();

            if(a==b)continue;
            else maxH.push(a-b);

        }
        return maxH.size() == 0 ? 0 : maxH.top();
    }
};
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxH;
        int ans =0;
        for(auto it:piles)maxH.push(it);

        while(k!=0 && !maxH.empty()){
            int val = maxH.top();
            maxH.pop();
            if(val&1)maxH.push((val/2)+1);
            else maxH.push(val/2);         
            k--;
        }

        if(k==0){
            while(!maxH.empty()){
                ans+=maxH.top();
                maxH.pop();
            }
        }else if(maxH.empty()) ans =0;

        return ans;

    }
};
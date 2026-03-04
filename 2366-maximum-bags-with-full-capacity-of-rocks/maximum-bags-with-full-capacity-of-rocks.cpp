class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>needed(n,0);
        for(int i=0;i<n;i++){
            needed[i] = capacity[i]-rocks[i];
        }
        long long sum = accumulate(needed.begin(),needed.end(),0LL);
        if(sum<additionalRocks) return n;

        sort(needed.begin(),needed.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(needed[i]!=0){
                if(additionalRocks==0)break;
                if(additionalRocks>=needed[i]){           
                    additionalRocks-=needed[i];
                    cnt++;
                    //needed[i]=0;
                }
        
            }else cnt++;
        }
        // for(auto it:needed)cout<<it<<" ";
        // int cnt = count(needed.begin(),needed.end(),0);
        return cnt;
    }
};
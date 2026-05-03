class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int>freq(1e4+1, 0);
        for(auto it : barcodes)freq[it]++;
        int maxCnt =0,val=0;
        for(int i=1;i<=10000;i++){
            if(freq[i] > maxCnt){
                maxCnt = freq[i];
                val = i;
            }
        }
        vector<int>ans = barcodes;
        int i=0;
        while(freq[val] > 0){
            ans[i] = val;
            freq[val]--;
            i+=2;
        }

        for(int val=0;val<=10000;val++){
            while(freq[val] > 0){
                if(i>=n)i=1;
                ans[i]=val;
                freq[val]--;
                i+=2;
            }
        }
        return ans;
    }
};
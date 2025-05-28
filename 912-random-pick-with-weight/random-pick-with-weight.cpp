class Solution {
public:
    vector<int>cummSum;
    Solution(vector<int>& w) {
        int n =w.size();
        cummSum.resize(n);
        cummSum[0]=w[0];
        for(int i=1;i<n;i++){
            cummSum[i]=cummSum[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int number = rand()%cummSum.back();
        int ind = upper_bound(cummSum.begin(),cummSum.end(),number)-cummSum.begin();
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
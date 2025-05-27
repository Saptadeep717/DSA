class Solution {
public:
   #define pb push_back
   static bool cmp( const int val,const vector<int> &a) {
    return val<a[0];  
}
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<vector<int>> diffInd;
        int n = difficulty.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            diffInd.pb({difficulty[i], profit[i], i});
        }
        sort(diffInd.begin(), diffInd.end());
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, diffInd[i][1]);
            diffInd[i][1] = maxProfit;
        }

        for (int i = 0; i < worker.size(); i++) {
            auto it = upper_bound(diffInd.begin(), diffInd.end(), worker[i],cmp);

           if (it != diffInd.begin()) {
                --it;
                sum += (*it)[1];
            }
        
        }

        return sum;
    }
};
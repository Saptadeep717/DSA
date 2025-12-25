class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long cnt =0, ans = 0, j=n-1;
        while(cnt < k){
            int val =  happiness[j] - cnt;
            ans+= (val > 0) ? val : 0;
            j--;
            cnt++;

        }
        return ans;
    }
};
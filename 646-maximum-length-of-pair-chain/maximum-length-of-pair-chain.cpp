class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int cnt = 1;
        sort(pairs.begin(), pairs.end() , [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        int prev = pairs[0][1];
        for(int i=1;i<n;i++){
            if(pairs[i][0] > prev ){
                cnt++;
                prev = pairs[i][1];
            }
        }
        return cnt;
    }
};
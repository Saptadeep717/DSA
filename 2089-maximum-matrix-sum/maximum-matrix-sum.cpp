class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt =0;
        int mini = INT_MAX;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mini = min(mini, abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    sum-=matrix[i][j];
                    cnt++;
                   
                }else sum+=matrix[i][j];
            }
        }

        if(cnt&1) return sum - 2*mini;
        return sum;
    }
};
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt =0;
        int n = grid.size(), m = grid[0].size();
        int j = (n*m)-1;
        while(j>=0){
            if(grid[j/m][j%m] < 0) cnt++;
            j--;
        }
        return cnt;
    }
};
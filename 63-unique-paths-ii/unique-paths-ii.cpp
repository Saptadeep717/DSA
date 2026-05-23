class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // dp[r][c] = number of unique paths
        // to reach cell (r,c) from (0,0)
        //vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case:
        // There is exactly 1 way to stand at starting cell
        //dp[0][0] = 1;

        vector<int>prev(n,0);
        // Traverse the grid row by row
        for(int r = 0; r < m; r++) {
            vector<int>curr(n,0);
            for(int c = 0; c < n; c++) {

                if(r>=0 && c>=0 && obstacleGrid[r][c] == 1){
                    curr[c] = 0;
                    continue;
                }
                
                // Skip the starting cell
                // because we already filled it
                if(r == 0 && c == 0){
                    curr[c] = 1;
                     continue;
                }

                
                   

                int up = 0;
                int left = 0;

                // If upper cell exists,
                // take paths coming from top
                if(r > 0)
                    //up = dp[r - 1][c];
                    up = prev[c];

                // If left cell exists,
                // take paths coming from left
                if(c > 0)
                    //left = dp[r][c - 1];
                    left = curr[c - 1];

                // Total paths to current cell
                //dp[r][c] = up + left;
                curr[c] = up + left;
            }
            prev = curr;
        }

        // Bottom-right cell contains final answer
        //return dp[m - 1][n - 1];
        return prev[n-1];
    }
};
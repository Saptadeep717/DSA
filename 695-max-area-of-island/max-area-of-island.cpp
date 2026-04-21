class Solution {
public:
    int n, m;
    int dfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>& grid){
        int cnt = 1;
        vis[row][col] = 1;
        int dx[4] = {-1,0,0,1}, dy[4] = {0,1,-1,0};
        for(int k=0;k<4;k++){
            int nr = row + dx[k];
            int nc = col + dy[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && !vis[nr][nc]){
                cnt+= dfs(nr,nc,vis,grid);
            }
        }
        return cnt;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    ans = max(ans,dfs(i,j,vis,grid));
                    cout<<ans<<" ";
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int n,m;
    void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[row][col] = 1;

        int dx[4] = {-1,0,0,1}, dy[4] = {0,1,-1,0};

        for(int k=0;k<4;k++){
            int nr = row+dx[k];
            int nc = col+dy[k];

            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
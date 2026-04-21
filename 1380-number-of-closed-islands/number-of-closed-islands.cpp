class Solution {
public:
    int n, m;
    void dfs(int r, int c, vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[r][c]=1;
        int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};
        for(int k=0;k<4;k++){
            int nr = r+dx[k], nc = c+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==0){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool boundary0s = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && vis[i][j]==0 && grid[i][j]==0){
                    dfs(i,j,vis,grid);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
                cout<< vis[i][j]<<" ";
            }cout<<"\n";
        }
        return cnt;
    }
};
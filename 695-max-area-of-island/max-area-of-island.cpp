class Solution {
public:
    
    int dfs(int i, int j,vector<vector<bool>>&vis,vector<vector<int>>& grid, int n, int m, int &cnt ){
        vis[i][j]=1;
        cnt+=1;
        int dx[4] = {0,-1,+1,0};
        int dy[4] = {+1,0,0,-1};

        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
                dfs(ni,nj,vis,grid,n,m,cnt);
            }

        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi=0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){         
            for(int j=0;j<m;j++){
                int c =0;
                if(grid[i][j]==1 && !vis[i][j]){
                    maxi = max(maxi,dfs(i,j,vis,grid,n,m,c));
                }
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        if(grid[0][0]==0)q.push({0,0,1});

        while(!q.empty()){
            auto [row,col,level] = q.front();
            q.pop();
            if(row==n-1 && col==m-1) return level;
            int dx[8]={-1,0,0,1,1,1,-1,-1}, dy[8]={0,1,-1,0,1,-1,1,-1};
            for(int k=0;k<8;k++){
                int nr = row + dx[k], nc = col + dy[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==0 ){
                    q.push({nr,nc,level+1});
                    vis[nr][nc]=1;
                }
            }
        }

        return -1;
    }
};
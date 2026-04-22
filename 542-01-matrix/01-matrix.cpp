class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto [row,col,level] = q.front();
            q.pop();
            ans[row][col] = level;
            int dx[4]={-1,0,0,1}, dy[4]={0,1,-1,0};
            for(int k=0;k<4;k++){
                int nr = row + dx[k], nc = col + dy[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({nr,nc,level+1});
                    vis[nr][nc]=1;
                }
            }
        }

        return ans;

    }
};
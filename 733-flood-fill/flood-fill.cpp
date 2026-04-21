class Solution {
public:
    int n, m;
    void dfs(int r, int c,vector<vector<int>>&vis,vector<vector<int>>& image,int cl){
        vis[r][c] = 1;

        int dx[4] = {-1,0,0,1}, dy[4] = {0,1,-1,0};

        for(int k=0;k<4;k++){
            int nr = r + dx[k], nc = c + dy[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[nr][nc]==cl){
                dfs(nr,nc,vis,image,cl);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans = image;
        int c = image[sr][sc];
        dfs(sr,sc,vis,image,c);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<vis[i][j]<<" ";
                if(ans[i][j]==c && vis[i][j]) ans[i][j] = color;
            }cout<<endl;
        }
        return ans;

    }
};
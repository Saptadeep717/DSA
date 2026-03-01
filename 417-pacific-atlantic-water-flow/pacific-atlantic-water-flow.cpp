class Solution {
public:
    void DFS(int i, int j,vector<vector<int>>& heights,vector<vector<bool>>&vis, int prevVal ){
        //invalid state
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size()) return;

        if(vis[i][j] || prevVal>heights[i][j]) return;
        vis[i][j] = 1;
        int dx[4]= {-1,+1,0,0};
        int dy[4]= {0,0,-1,+1};

        for(int k=0;k<4;k++){
            int ni= i+dx[k];
            int nj = j+dy[k];

            DFS(ni,nj,heights,vis,heights[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pacificVis(n,vector<bool>(m,0));
        vector<vector<bool>>atlanticVis(n,vector<bool>(m,0));
        vector<vector<int>>ans;
        //1st row connected with pacific and last row connected with atlantic
        for(int j=0;j<m;j++){
            DFS(0,j,heights,pacificVis,-1);
            DFS(n-1,j,heights,atlanticVis,-1);
        }
        //1st col connected with pacific and last col connected with atlantic
        for(int i=0;i<n;i++){
            DFS(i,0,heights,pacificVis,-1);
            DFS(i,m-1,heights,atlanticVis,-1);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacificVis[i][j] && atlanticVis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
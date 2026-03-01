class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>& board, int n, int m){
        vis[i][j]=1;
        int dx[4] = {0,-1,+1,0};
        int dy[4] = {+1,0,0,-1};

        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && board[ni][nj]=='O'){

                dfs(ni,nj,vis,board,n,m);
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    if(i==0 || i==n-1 || j==0 || j==m-1)
                        dfs(i,j,vis,board,n,m);
                }
            }
        }

        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cout<<vis[i][j]<<" ";
            }cout<<endl;
        }

        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
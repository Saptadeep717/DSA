class Solution {
public:
    int n,m;
    void dfs(int row, int col,vector<vector<int>>&vis, vector<vector<char>>& board){
        vis[row][col] = 1;

        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,+1,0};

        for(int k=0;k<4;k++){
            int newRow = row + dx[k];
            int newCol = col + dy[k];

            if(newRow >=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && board[newRow][newCol]=='O'){
                dfs(newRow,newCol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
         n = board.size(), m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && !vis[i][j] && board[i][j]=='O') 
                    dfs(i,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O') 
                    board[i][j]='X';
            }
        }

        
    }
};
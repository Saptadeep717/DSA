class Solution {
public:
    int queen[20];

    bool isValid(int row, int col,vector<string>&board){
        for(int i=0;i<row;i++){
            int prevRow = i;
            int prevCol = queen[i];

            if(col==prevCol || abs(row-prevRow) == abs(col-prevCol)) return false;
        }
        return true;
    }

    void solve(int n, vector<string>&board, vector<vector<string>>&ans, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isValid(row,col,board)){
                board[row][col]='Q';
                queen[row]=col;
                solve(n,board,ans,row+1);
                board[row][col]='.';
                queen[row]=-1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        memset(queen,-1,sizeof(queen));
        vector<string>board(n,string(n,'.'));
        solve(n,board,ans,0);
        return ans;

    }
};
class Solution {
public:
    bool isEven(int val){
        return (val==2 || val==4 || val==6 || val==8);
    }

    bool isMagic(int r, int c, vector<vector<int>>&grid){
        if( grid[r+1][c+1] != 5) return false;
        if( !isEven(grid[r][c]) ||  !isEven(grid[r+2][c]) || !isEven  (grid[r][c+2]) || !isEven(grid[r+2][c+2])) return false;
        vector<int>seen(10,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int val = grid[r+i][c+j];
                if(val < 1 || val > 9 || seen[val]==1) return false;
                seen[val] = 1;
            }
        }
        // row sum check
        for(int i=0;i<3;i++){
           if((grid[r+i][c]) + (grid[r+i][c+1]) + (grid[r+i][c+2]) != 15) return false;
        }
        
        //col check
         for(int j=0;j<3;j++){
           if((grid[r][c+j]) + (grid[r+1][c+j]) + (grid[r+2][c+j]) != 15) return false;
        }

        // diagonal check
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15) return false;


        return true;


    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt =0;
        for(int i =0; i <n-2; i++){
            for(int j =0; j< m-2; j++){
                cnt+= isMagic(i,j, grid);
            }
        }

        return cnt;
    }

};
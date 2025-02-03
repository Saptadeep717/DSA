class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
      vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                set<int>left,right;

                int r =i-1,c=j-1;
                while(r>=0 && c>=0) left.insert(grid[r--][c--]);
                r =i+1,c=j+1;
                while(r<grid.size() && c<grid[0].size()) right.insert(grid[r++][c++]);
                int lval = left.size(), rval=right.size();
                ans[i][j] = abs(lval-rval);
                
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;  
    vector<vector<int>> h(n, vector<int>(m, -1));  
    
    if (grid[0][0] == 1) {
        q.push({health - 1, {0, 0}});
    } else {
        q.push({health, {0, 0}});
    }
    h[0][0] = q.front().first;  
    
    while (!q.empty()) {
        int val = q.front().first;           
        int row = q.front().second.first;    
        int col = q.front().second.second; 
        q.pop();  
        
        if (row == n - 1 && col == m - 1 && val>=1) return true;
        
       
        
        int di[4] = {0, -1, 0, 1};  
        int dj[4] = {-1, 0, 1, 0};
        
        for (int k = 0; k < 4; k++) {
            int ni = row + di[k];
            int nj = col + dj[k];
            if (ni>= 0 && ni < n && nj >= 0 && nj < m) {
                int newHealth = (grid[ni][nj] == 0) ? val : val - 1;
                if (newHealth > h[ni][nj]) {  
                    h[ni][nj] = newHealth;
                    q.push({newHealth, {ni, nj}});
                }
            }
        }
    }
    
    return false;
    }
};
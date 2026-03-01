class Solution {
public:
    using p = pair<int, int>;
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        //vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<p, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        if(q.size()==n*m) return -1;
        int maxi = -1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            //ans[r][c] = dis;
            maxi = max(maxi,dis);

            int dx[4] = {0, -1, +1, 0};
            int dy[4] = {+1, 0, 0, -1};

            for (int k = 0; k < 4; k++) {
                int ni = r + dx[k];
                int nj = c + dy[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
                    q.push({{ni, nj}, dis + 1});
                    vis[ni][nj] = 1;
                }
            }
        }
        return maxi;


    }
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        int x[4] = {-1, 0, 0, 1}, y[4] = {0, -1, 1, 0};
        vis[entrance[0]][entrance[1]] = true;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) && (row!=entrance[0] || col!=entrance[1])) {
                return step;
            }
            for (int i = 0; i < 4; i++) {
                int nr = row + x[i];
                int nc = col + y[i];
                if (nr >= 0 && nr <= n - 1 && nc >= 0 && nc <= m - 1 &&
                    !vis[nr][nc] && maze[nr][nc] == '.') {
                    q.push({{nr, nc}, step + 1});
                    vis[nr][nc] = 1;
                }
            }
        }

        return -1;
    }
};
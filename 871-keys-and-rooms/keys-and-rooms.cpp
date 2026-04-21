class Solution {
public:
    void dfs(int room, unordered_map<int, vector<int>>& adjList,
             vector<bool>& vis) {
        vis[room] = true;

        for (auto neiRoom : adjList[room]) {
            if (!vis[neiRoom]) {
                dfs(neiRoom, adjList, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < n; i++) {
            for (int x : rooms[i]) {
                adjList[i].push_back(x);
            }
        }
        vector<bool> vis(n, false);

        dfs(0, adjList, vis);

        for (auto it : vis) {
            if (it == false)
                return false;
        }
        return true;
    }
};
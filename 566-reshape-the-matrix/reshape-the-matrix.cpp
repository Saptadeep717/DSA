class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        vector<int> v;
        if (n * m != r * c)
            return mat;

        vector<vector<int>> ans(r, vector<int>(c));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back(mat[i][j]);
            }
        }
        for (auto it : v)
            cout << it << " ";
        int k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = v[k++];
            }
        }
        return ans;
    }
};
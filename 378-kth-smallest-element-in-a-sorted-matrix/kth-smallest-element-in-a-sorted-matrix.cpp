class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int>temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(mat[i][j]);
            }
        }

        sort(temp.begin(),temp.end());
        //for(auto it:temp) cout<<it<<" ";
        return temp[k-1];

    }
};
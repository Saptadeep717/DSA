class Solution {
public:

    int possible(vector<vector<int>>& m,int val){
        int n = m.size();
        int col = n-1;
        int c=0;
        for(int row=0;row<n;row++){
            while(col>=0 && m[row][col]>val) col--;
            c+=col+1;
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int start =mat[0][0],end=mat[n-1][n-1];
        int ans=-1;
        while(start<=end){
            int mid = (start+end)/2;

            if(possible(mat,mid) >= k){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;

        }

        return ans;

    }
};
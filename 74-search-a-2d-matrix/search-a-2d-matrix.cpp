class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if(matrix[n-1][m-1] < target) return false;
        int i =0, j = n*m;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]>target) j=mid-1;
            else i = mid+1;
        }
        return false;
    }
};
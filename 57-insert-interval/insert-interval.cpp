class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& temp){
        int n = temp.size();
        vector<vector<int>>ans;
        for(int i=0; i<n ;i++){
            if(!ans.empty() && ans.back()[1] >= temp[i][0]) ans.back()[1] = max(ans.back()[1], temp[i][1]);
            else ans.push_back(temp[i]);
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp = intervals;
        temp.push_back(newInterval);

        sort(temp.begin(), temp.end());
        
        vector<vector<int>> ans = mergeInterval(temp);
        return ans;

    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> temp;
        int n = score.size();
        for (int i = 0; i < n; i++) {
            temp.push_back({score[i], i});
        }

        sort(temp.rbegin(), temp.rend());
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = temp[i].second;
            if (i == 0)
                ans[idx] = "Gold Medal";
            else if (i == 1)
                ans[idx] = "Silver Medal";
            else if (i == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(i + 1);
        }
        return ans;
    }
};
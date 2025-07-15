class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> l;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                l.push_back(arr[i]);
            } else {
                while (!l.empty() && l.back() > 0 && l.back() < abs(arr[i]))
                    l.pop_back();

                if (!l.empty() && l.back() == abs(arr[i])) {
                    l.pop_back();
                }

                else if (l.empty()  ||
                         (l.back() < 0)) {
                    l.push_back(arr[i]);
                }
            }
        }
        return l;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        if (n == 0) return tasks.size();

        int maxFreq = 0;
        for (char t : tasks) {
            count[t - 'A']++;
            maxFreq = max(maxFreq, count[t - 'A']);
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == maxFreq) cnt++;
        }

        int ans = (maxFreq - 1) * (n + 1) + cnt;

        return max((int)tasks.size(), ans);
    }
};

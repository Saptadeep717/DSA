class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxConsecutiveHBars = 1;
        int maxConsecutiveVBars = 1;
        int maxiHB=1, maxiVB=1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1)
                maxConsecutiveHBars++;
            else
                maxConsecutiveHBars = 1;

            maxiHB = max(maxiHB, maxConsecutiveHBars);
        }

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1)
                maxConsecutiveVBars++;
            else
                maxConsecutiveVBars = 1;

            maxiVB = max(maxiVB, maxConsecutiveVBars);
        }

        int side = min(maxiVB, maxiHB) + 1;

        return side*side;
    }
};

class Solution {
public:

    long long catalan(int n) {
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * 2 * (2 * i + 1) / (i + 2);
        }
        return res;
    }
int numTrees(int n) {
    return catalan(n);
}
};
class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, n - 1, 0);
    }

    void build(vector<int>& nums, int s, int e, int i) {
        if (s == e) {
            seg[i] = nums[s];
            return;
        }

        int m = s + (e - s) / 2;

        build(nums, s, m, 2 * i + 1);
        build(nums, m + 1, e, 2 * i + 2);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void upd(int s, int e, int index, int val, int i) {
        if (s == e) {
            seg[i] = val;
            return;
        }

        int m = s + (e - s) / 2;

        if (index <= m)
            upd(s, m, index, val, 2 * i + 1);
        else
            upd(m + 1, e, index, val, 2 * i + 2);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void update(int index, int val) {
        upd(0, n - 1, index, val, 0);
    }

    int query(int left, int right, int s, int e, int i) {

        if (e < left || s > right)
            return 0;

        if (s >= left && e <= right)
            return seg[i];

        int m = s + (e - s) / 2;

        return query(left, right, s, m, 2 * i + 1)
             + query(left, right, m + 1, e, 2 * i + 2);
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, n - 1, 0);
    }
};
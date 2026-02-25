class NumArray {
public:
    vector<int> seg;
    vector<int> numss;
    NumArray(vector<int>& nums) {
        numss = nums;
        int n = numss.size();
        seg.resize(4 * n);
        build(0, n - 1, 0);
    }

    void build(int s, int e, int i) {
        if (s == e) {
            seg[i] = numss[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(s, m, 2 * i + 1);
        build(m + 1, e, 2 * i + 2);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void upd(int s, int e, int index, int val, int i) {
        if (s == e) {
            seg[i] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            upd(s, m, index, val, 2 * i + 1);
        } else {
            upd(m + 1, e, index, val, 2 * i + 2);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void update(int index, int val) {
        int n = numss.size();
        upd(0, n - 1, index, val, 0);
    }

    int query(int left, int right, int start, int end, int idx) {

        if (start > right || end < left)
            return 0;
        if (start >= left && right >= end)
            return seg[idx];

        int m = start + (end - start) / 2;
        return query(left, right, start, m, 2 * idx + 1) +
               query(left, right, m + 1, end, 2 * idx + 2);
    }

    int sumRange(int left, int right) {
        int n = numss.size();
        return query(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
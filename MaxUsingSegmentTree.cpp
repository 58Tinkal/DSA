class SegmentTree {
private:
    int n;
    vector<int> tree;  // segment tree array

    // build function
    void build(vector<int>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * idx + 1, l, mid);
        build(arr, 2 * idx + 2, mid + 1, r);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    // query max in range [ql, qr]
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INT_MIN; // outside range
        if (ql <= l && r <= qr) return tree[idx]; // fully inside
        int mid = (l + r) / 2;
        return max(query(2 * idx + 1, l, mid, ql, qr),
                   query(2 * idx + 2, mid + 1, r, ql, qr));
    }

    // update position pos with new value val
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MIN);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
};

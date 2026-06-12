class SegTree {
public:
    int n;
    vector<long long> st;

    SegTree(int n) : n(n) {
        st.assign(4 * n, LLONG_MIN);
    }

    void update(int p, long long val,
                int node, int l, int r) {
        if (l == r) {
            st[node] = max(st[node], val);
            return;
        }

        int mid = (l + r) >> 1;

        if (p <= mid)
            update(p, val, node * 2, l, mid);
        else
            update(p, val, node * 2 + 1, mid + 1, r);

        st[node] = max(st[node * 2],
                       st[node * 2 + 1]);
    }

    long long query(int L, int R,
                    int node, int l, int r) {
        if (R < l || r < L)
            return LLONG_MIN;

        if (L <= l && r <= R)
            return st[node];

        int mid = (l + r) >> 1;

        return max(
            query(L, R, node * 2, l, mid),
            query(L, R, node * 2 + 1, mid + 1, r)
        );
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()),
                   vals.end());

        int m = vals.size();

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[i] =
                lower_bound(vals.begin(),
                            vals.end(),
                            nums[i]) - vals.begin() + 1;
        }

        vector<long long> up(n), down(n);

        SegTree segUp(m), segDown(m);

        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {

            if (i - k >= 0) {
                segUp.update(rank[i - k],
                             up[i - k],
                             1, 1, m);

                segDown.update(rank[i - k],
                               down[i - k],
                               1, 1, m);
            }

            up[i] = down[i] = nums[i];

            int r = rank[i];

            if (r > 1) {
                long long best =
                    segDown.query(1, r - 1,
                                  1, 1, m);

                if (best != LLONG_MIN)
                    up[i] = max(up[i],
                                best + nums[i]);
            }

            if (r < m) {
                long long best =
                    segUp.query(r + 1, m,
                                1, 1, m);

                if (best != LLONG_MIN)
                    down[i] = max(down[i],
                                  best + nums[i]);
            }

            ans = max(ans, max(up[i], down[i]));
        }

        return ans;
    }
};
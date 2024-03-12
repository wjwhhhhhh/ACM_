#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class Info> struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree(string &a)
    {
        n = a.size();
        info.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(l, a[l]);
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
            info[p] = info[p << 1] + info[p << 1 | 1];
        };
        build(1, 1, n);
    }
    void modify(int p, int l, int r, int x, char c)
    {
        if (x == l && l == r)
        {
            info[p].init(l, c);
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid)
            modify(p << 1, l, mid, x, c);
        else
            modify(p << 1 | 1, mid + 1, r, x, c);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int x, int c)
    {
        modify(1, 1, n, x, c);
    }
    Info query(int p, int l, int r, int ll, int rr)
    {
        if (ll == l && rr == r)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        if (ll <= mid && rr <= mid)
            return query(p << 1, l, mid, ll, min(rr, mid));
        else if (rr > mid && ll > mid)
            return query(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
        else
            return query(p << 1, l, mid, ll, min(rr, mid)) + query(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
    }
    Info query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }
};
struct Info
{
    struct node
    {
        int len, l;
        char val;
        node()
        {
            len = 0, l = 0, val = '0';
        }
    };
    node ans, left, right;
    void init(int y, char c)
    {
        ans.len = left.len = right.len = 1;
        ans.val = left.val = right.val = c;
        ans.l = left.l = right.l = y;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info t;
        if (a.right.val == b.left.val)
        {
            int tem = a.right.len + b.left.len;
            if (tem >= t.ans.len)
            {
                t.ans = a.right;
                t.ans.len = tem;
            }
        }
        if (a.ans.len > t.ans.len || (a.ans.len == t.ans.len && a.ans.l < t.ans.l))
        {
            t.ans = a.ans;
        }
        if (b.ans.len > t.ans.len || (b.ans.len == t.ans.len && b.ans.l < t.ans.l))
        {
            t.ans = b.ans;
        }
        t.left = a.left, t.right = b.right;
        if (a.left.l == a.right.l && a.left.val == b.left.val)
        {
            t.left.len += b.left.len;
        }
        if (b.right.val == a.right.val && b.right.l == b.left.l)
        {
            t.right = a.right;
            t.right.len += b.right.len;
        }
        return t;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    a = " " + a;
    SegmentTree<Info> seg(a);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            auto get = seg.query(l, r);
            cout << get.ans.l << " " << get.ans.l + get.ans.len - 1 << endl;
        }
        else
        {
            int x;
            char ch;
            cin >> x >> ch;
            seg.modify(x, ch);
        }
    }
    // auto get = seg.query(4, 5);
    // cout << get.left.len << endl;
    return 0;
}
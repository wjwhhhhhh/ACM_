#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
string op;
template <class Info> struct SegmentTree
{
    int n;
    string op;
    vector<Info> info;
    SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(a[l], l);
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
            info[p] = info[p << 1] + info[p << 1 | 1];
        };
        build(1, 1, n);
    }
    void modify(int p, int l, int r, int x, int c)
    {
        if (x == l && l == r)
        {
            info[p].init(c, l);
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
    bool val[30][2];
    Info()
    {
        memset(val, 0, sizeof val);
    }
    void init(int x, int l)
    {
        for (int i = 29; i >= 0; i--)
        {
            int k = x >> i & 1;
            if (op[l] == '|')
                val[i][0] = 0 | x, val[i][1] = 1 | x;
            else if (op[l] == '^')
                val[i][0] = 0 ^ x, val[i][1] = 1 | x;
            else if (op[l] == '&')
                val[i][0] = 0 & x, val[i][1] = 1 & x;
        }
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        for (int i = 29; i >= 0; i--)
        {
            ans.val[i][1] = b.val[i][a.val[i][1]];
            ans.val[i][0] = b.val[i][a.val[i][0]];
        }
        return ans;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    cin >> op;
    op = " " + op;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    SegmentTree<Info> seg(w);
    int q;
    cin >> q;

    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            int a, b;
            cin >> a >> b;
            seg.modify(a, b);
        }
        else
        {
            int x, l, r;
            cin >> x >> l >> r;
            auto get = seg.query(l, r);
            int ans = 0;
            for (int i = 29; i >= 0; i--)
            {
                int k = x >> i & 1;
                ans += (get.val[i][k] << i);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
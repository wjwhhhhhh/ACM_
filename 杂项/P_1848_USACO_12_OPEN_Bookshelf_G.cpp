#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
#define int long long
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
template <class Info> struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(a[l - 1]);
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
            info[p].init(c);
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
        if (l == 0)
            l = 1;
        return query(1, 1, n, l, r);
    }
};
struct Info
{
    int val;
    Info() : val(0)
    {
    }
    void init(int x)
    {
        val = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        if (a.val > b.val)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, L;
    cin >> n >> L;
    vector<int> h(n + 2), w(n + 2);
    vector<i64> s(n + 2);
    for (int i = 2; i <= n + 1; i++)
        cin >> w[i] >> h[i];
    for (int i = 2; i <= n + 1; i++)
        s[i] = s[i - 1] + h[i];
    vector<int> q(n + 2);
    int hh = 0, tt = -1;
    q[++tt] = 1;
    vector<int> f(n + 2);
    SegmentTree<Info> seg(f), seh(f);
    for (int i = 2; i <= n + 1; i++)
    {
        while (hh <= tt && s[i] - s[q[hh] - 1] > L)
        {
            hh++;
        }
        while (hh <= tt && w[i] > w[q[tt]])
        {
            tt--;
        }
        int l = 1, r = i;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (s[i] - s[mid - 1] <= L)
                r = mid;
            else
                l = mid + 1;
        }
        q[++tt] = i;
        int res = 0;
        if (hh == tt)
        {
            res = seg.query(l - 1, i - 1).val + w[i];
        }
        else
        {
            // cerr << l - 1 << endl;
            res = seg.query(l - 1, q[hh] - 1).val + w[q[hh]];
            seh.modify(tt, seg.query(q[tt - 1], q[tt] - 1).val + w[i]);
            chkmin(res, seh.query(hh + 1, tt).val);
        }
        f[i] = res;
        seg.modify(i, f[i]);
    }
    cout << f[n + 1] << endl;
    return 0;
}
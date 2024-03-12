#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
        return query(1, 1, n, l, r);
    }
};
struct Info
{
    int mi, mx;
    Info()
    {
    }
    void init(int x)
    {
        mi = mx = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        ans.mi = min(a.mi, b.mi);
        ans.mx = max(a.mx, b.mx);
        return ans;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree<Info> seg(a);
    vector<pair<int, int>> ans;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            auto get = seg.query(i + 1, mid + 1);
            if (get.mx - get.mi <= k)
                l = mid;
            else
                r = mid - 1;
        }
        int len = l - i + 1;
        if (len > res)
        {
            res = len;
            ans.clear();
            ans.push_back({i, l});
        }
        else if (len == res)
        {
            ans.push_back({i, l});
        }
    }
    cout << res << " " << ans.size() << endl;
    for (auto [x, y] : ans)
    {
        cout << x + 1 << ' ' << y + 1 << endl;
    }
    return 0;
}
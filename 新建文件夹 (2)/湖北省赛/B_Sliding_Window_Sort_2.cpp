#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
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
    Info(int a = 0, int b = 0) : mi(a), mx(b)
    {
    }
    void init(int x)
    {
        mi = mx = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info c;
        c.mi = min(a.mi, b.mi);
        c.mx = max(a.mx, b.mx);
        return c;
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
    if (k == 1)
    {
        for (auto c : a)
            cout << c << " ";
        return 0;
    }
    vector<int> cha(n);
    for (int i = 1; i < n; i++)
        cha[i] = a[i] - a[i - 1];
    SegmentTree<Info> seg(a);
    SegmentTree<Info> scha(a);
    int ans = 1;
    auto query = [&](int l, int r) {
        if (l > r)
            return Info(1, 1);
        else
            return scha.query(l, r);
    };
    auto check = [&](int x, int y) {
        if (x + k - 1 >= y)
        {
            if (seg.query(y, x + k - 1).mi < seg.query(x, y - 1).mx)
                return false;
            if (query(x + 1, x + k - 1).mi < 0)
                return false;
            if (seg.query(x + k, y + k - 1).mi < seg.query(y, x + k - 1).mx)
                return true;
            if (query(x + k + 1, y + k - 1).mi < 0)
                return true;
        }
        else
        {
            if (query(x, x + k - 1).mi < 0)
                return false;
            if (query(y, y + k - 1).mi < 0)
                return true;
        }
        return true;
    };
    for (int i = 2; i + k - 1 <= n; i++)
    {
        if (!check(ans, i))
            ans = i;
    }
    sort(a.begin() + ans - 1, a.begin() + ans - 1 + k);
    for (auto c : a)
        cout << c << " ";
    return 0;
}